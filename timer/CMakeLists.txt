﻿PROJECT(test_timer)

#寮曠敤澶存枃浠剁洰褰?
if(WIN32)
	INCLUDE_DIRECTORIES(
		${BLOCK_PATH}/
		${BLOCK_PATH}/modules
		${BLOCK_PATH}/3rd/lua-5.3.4/src
		${BLOCK_PATH}/3rd/sol2
		${BLOCK_PATH}/3rd/fmt
		${BLOCK_PATH}/3rd/glog/src
	)
	Add_Definitions("-DGLOG_NO_ABBREVIATED_SEVERITIES")
endif()
if(UNIX)
	INCLUDE_DIRECTORIES(
		${BLOCK_PATH}/
		${BLOCK_PATH}/modules
		${BLOCK_PATH}/lib/glog/include
		${BLOCK_PATH}/lib/lua
		${BLOCK_PATH}/3rd/sol2
		${BLOCK_PATH}/lib/fmt/include
	)
endif()
if(APPLE)
	INCLUDE_DIRECTORIES(
		${BLOCK_PATH}/
		${BLOCK_PATH}/modules
    )
endif()


#寮曠敤搴撶洰褰?
if(WIN32)
	LINK_DIRECTORIES(
	${BLOCK_PATH}/lib/win/Debug
	)
endif()
if(UNIX)
	find_package(Threads)
	LINK_DIRECTORIES(
		${BLOCK_PATH}/lib
		${BLOCK_PATH}/lib/lua
		${BLOCK_PATH}/lib/glog/lib
		${BLOCK_PATH}/lib/fmt/lib
	)
endif()
if(APPLE)
endif()

FILE(GLOB_RECURSE SRC "*.cpp" "*.h")
ADD_EXECUTABLE(test_timer ${SRC})

if(MSVC)
    # Use the static C library for all build types
    foreach(var
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
      )
      if(${var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${var} "${${var}}")
      endif()
    endforeach()

        TARGET_LINK_LIBRARIES(test_timer ws2_32.lib libevent.lib libevent_core.lib libevent_extras.lib core.lib timer.lib glog.lib lua53.lib pbc.lib luaAdapter.lib fmt.lib)
elseif(UNIX)
	if ("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 3.1)
		target_link_libraries(test_timer ${CMAKE_THREAD_LIBS_INIT})
	else()
		target_link_libraries(test_timer Threads::Threads)
	endif()

    TARGET_LINK_LIBRARIES(test_timer liblog.a libglog.a libgsf_core.a liblua_proxy.a liblua.a libtimer.a libfmt.a -ldl)
elseif(APPLE)
endif()
