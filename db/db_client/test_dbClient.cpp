#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include <sys/types.h>

#include <fmt/format.h>

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include <core/application.h>
#include <core/event.h>

#include <network/acceptor.h>
#include <network/connector.h>

#include <distributed/node.h>
#include <timer/timer.h>
#include <lua_proxy/lua_proxy.h>

#include <log/log.h>
#include <iostream>

#include <fmt/format.h>

enum dbproxy_event
{
	db_update = 3000,
	db_sql,
	db_sqlcb,
};

class PathModule
	: public gsf::Module
	, public gsf::IEvent
{
public:

	PathModule()
		: Module("PathModule")
	{}

	virtual ~PathModule() {}

	void before_init()
	{
		char _path[512];

#ifdef WIN32
		GetModuleFileName(NULL, _path, 512);
		for (int i = strlen(_path); i >= 0; i--)
		{
			if (_path[i] == '\\')
			{
				_path[i] = '\0';
				break;
			}
		}
#else
		int cnt = readlink("/proc/self/exe", _path, 512);
		if (cnt < 0 || cnt >= 512) {
			std::cout << "read path err" << std::endl;
			return;
		}
		for (int i = cnt; i >= 0; --i)
		{
			if (_path[i] == '/') {
				_path[i + 1] = '\0';
				break;
			}
		}
#endif // WIN32

		path_ = _path;

		listen(this, eid::sample::get_proc_path, [=](const gsf::ArgsPtr &args) {
			return gsf::make_args(path_);
		});
	}

private:
	std::string path_ = "";
};


class Client2DBConnector
	: public gsf::network::ConnectorModule
{
public:
	Client2DBConnector()
		: gsf::network::ConnectorModule("Client2DBConnector")
	{}
};


class DBClientModule
	: public gsf::Module
	, public gsf::IEvent
{
public:
	DBClientModule()
		: Module("DBClientModule")
	{}

	virtual ~DBClientModule() {}

	void before_init() override
	{
		lua_m_ = dispatch(eid::app_id, eid::get_module, gsf::make_args("LuaProxyModule"))->pop_moduleid();
		assert(lua_m_ != gsf::ModuleNil);

		auto path_m_ = dispatch(eid::app_id, eid::get_module, gsf::make_args("PathModule"))->pop_moduleid();
		assert(path_m_ != gsf::ModuleNil);

		lua_path_ = dispatch(path_m_, eid::sample::get_proc_path, nullptr)->pop_string();

	}

	void init() override
	{
		dispatch(lua_m_, eid::lua_proxy::create, gsf::make_args(get_module_id(), lua_path_, "dbproxy/clientMain.lua"));
	}

	void shut() override
	{

	}

private:
	gsf::ModuleID lua_m_ = gsf::ModuleNil;
	std::string lua_path_ = "";
};

int main()
{
#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(1, 1);
	int result = WSAStartup(wVersionRequested, &wsaData);
	if (result != 0) {
		exit(1);
	}
#endif // WIN32

	gsf::Application app;
	gsf::AppConfig cfg;
	app.init_cfg(cfg);

	app.regist_module(gsf::EventModule::get_ptr());
	app.regist_module(new gsf::modules::LogModule());
	app.regist_module(new gsf::modules::NodeModule);
	app.regist_module(new gsf::modules::LuaProxyModule);
	app.regist_module(new gsf::modules::TimerModule);

	app.regist_module(new Client2DBConnector);

	app.regist_module(new PathModule);
	app.regist_module(new DBClientModule);

	app.run();

	return 0;
}