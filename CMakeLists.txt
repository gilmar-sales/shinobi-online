
cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(server)

# Revscriptsys2
set(VERSION "0.7.0")

# Options
option(USE_PGSQL "Use PGSQL" OFF)
option(USE_SQLITE "Use SQLite" ON)
option(USE_MYSQL "Use MySQL" ON)
option(USE_ODBC "Use ODBC" OFF)
option(USE_LUAJIT "Use LuaJIT" OFF)
option(USE_DIAGNOSTIC "Use server diagnostic" OFF)
option(USE_SKULLSYSTEM "Use Skull system" ON)
option(USE_STATIC_LIBS "Static linking" OFF)
option(USE_ROOT_PERMISSION "Use Root Permission" ON)
option(USE_DEBUG "Use debuging" ON)

# Status
message(STATUS "SQLite: " ${USE_SQLITE})
message(STATUS "MySQL: " ${USE_MYSQL})
message(STATUS "ODBC: " ${USE_ODBC})
message(STATUS "PGSQL: " ${USE_PGSQL})
message(STATUS "LuaJIT: " ${USE_LUAJIT})
message(STATUS "Use server diagnostic: " ${USE_DIAGNOSTIC})
message(STATUS "Static libraries: " ${USE_STATIC_LIBS})
message(STATUS "Server diagnostic: " ${USE_DIAGNOSTIC})
message(STATUS "Use Root Permission: " ${USE_ROOT_PERMISSION})
message(STATUS "Use debuging: " ${USE_DEBUG})


# Make sure at least one database driver is selected
if(NOT USE_MYSQL AND NOT USE_SQLITE AND NOT USE_ODBC AND NOT USE_PGSQL)
    message(FATAL_ERROR "At least one database driver has to be selected.")
endif()

# Sources
add_subdirectory(src)
add_subdirectory(data)
