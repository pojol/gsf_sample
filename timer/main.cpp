#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <sstream>
#include <iostream>

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include <core/application.h>
#include <core/dynamic_module_factory.h>

#include <timer/timer.h>

#include <log/log.h>
#include <luaAdapter/luaAdapter.h>


class TestCaseLuaModule
	: public gsf::modules::LuaAdapterModule
{
public:
	TestCaseLuaModule()
		: gsf::modules::LuaAdapterModule("TestCaseLuaModule")
	{}

	virtual ~TestCaseLuaModule() {}

	void before_init()
	{
		dir_ = "C:/github/gsf_sample/script";
		name_ = "test_timer.lua";
	}
};


int main()
{
	gsf::Application app;
	gsf::AppConfig cfg;
	//cfg.is_watch_pref = true;
	app.initCfg(cfg);

	APP.createModule(new gsf::modules::LogModule);
	APP.createModule(new gsf::modules::TimerModule);

	APP.createModule(new TestCaseLuaModule);

	app.run();

	return 0;
}
