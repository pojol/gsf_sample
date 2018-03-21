module = {
	before_init = function(dir) end,
	init = function() end,
	execute = function() end,
	shut = function() end,
	after_shut = function() end,
}

logM_ = 0
mysqlM_ = 0

module.before_init = function(dir)
	local package_path = {}
	table.insert(package_path, dir .. "/common/?.lua")
	package.path = table.concat(package_path, ';')

	require "utils"

	logM_ = APP:getModule("LogModule")
	INFO_LOG("mysql", "log : " .. logM_)

	mysqlM_ = APP:getModule("MysqlProxyModule")
	INFO_LOG("mysql", "dbProxy : " .. mysqlM_)
end

mysql_ip = "111.231.108.183"
mysql_usr = "root"
mysql_pwd = "234werSDF"
mysql_name = "Tmp"
mysql_port = 3306

local entity = {
	property = {
		id = 0,
        name = "''",
        hp = 100,
        lv = 1,
        loginTime = 0
	}
}

module.init = function()

	dispatch(mysqlM_, eid.dbProxy.connect, evpack:mysql_connect(mysql_ip, mysql_usr, mysql_pwd, mysql_name, mysql_port), function(args)
		DEBUG_LOG("mysql", "callback", args)
	end)

	_createSql = string.format("create table if not exists Entity(%s%s%s%s%s) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;"
		,"id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,"
		,"name VARCHAR(32) NOT NULL,"
		,"hp INT NOT NULL,"
		,"lv INT NOT NULL,"
		,"loginTime INT NOT NULL")

	listen(module_id, eid.dbProxy.callback, function(args)
		DEBUG_LOG("mysql", "callback", args)
	end)

	INFO_LOG("mysql", "create", _createSql)
	dispatch(mysqlM_, eid.dbProxy.query, evpack:dbQuery(module_id, _createSql))

	local _add = {}

	for k, val in pairs(entity.property) do
		table.insert(_add, k)
		table.insert(_add, val)
	end

	DEBUG_LOG("mysql", "insert entity", _add)
	dispatch(mysqlM_, eid.dbProxy.insert, evpack:dbInsert("Entity", _add))

	--dispatch(mysqlM_, eid::mysql_select, evpack:mysql_select("Entity", 1))

	--[[

	_entityID = 1
	_entityDirty = {
		"name",			-- key
		"'test1'"		-- value
	}
	dispatch(mysqlM_, eid.mysql_update, evpack:entity_update("Entity", _entityID, _entityDirty))
	
	]]--
end

module.execute = function()
end

module.shut = function()
end

module.after_shut = function()
end