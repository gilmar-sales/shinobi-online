cmake_minimum_required(VERSION 3.30)

file(GLOB OT_SOURCES ./*.cpp ./*.h)

if(USE_STATIC_LIBS)
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    SET(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif()

add_executable(${PROJECT_NAME} ${OT_SOURCES})

find_package(Boost REQUIRED COMPONENTS system iostreams filesystem thread)
find_package(libxml2 REQUIRED)
find_package(lua REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(httplib REQUIRED)

if(USE_ROOT_PERMISSION)
add_definitions(-D__ROOT_PERMISSION__)
endif ()

if(USE_DEBUG)
    add_definitions(-D__DEBUG__ -D__DEBUG_MOVESYS__ -D__DEBUG_CHAT__ -D__DEBUG_EXCEPTION_REPORT__ -D__DEBUG_HOUSES__ -D__DEBUG_LUASCRIPTS__ -D__DEBUG_MAILBOX__ -D__DEBUG_NET__ -D__DEBUG_NET_DETAIL__ -D__DEBUG_RAID__ -D__DEBUG_SCHEDULER__ -D__DEBUG_SPAWN__ -D__SQL_QUERY_DEBUG__)
endif ()

target_link_libraries(${PROJECT_NAME}
        boost::boost
        LibXml2::LibXml2
        lua::lua
        openssl::openssl
        httplib::httplib)

if(USE_STATIC_LIBS)
    find_package(ZLIB REQUIRED)
    find_package(Iconv REQUIRED)
    target_link_libraries(${PROJECT_NAME} ${ZLIB_LIBRARIES} ${ICONV_LIBRARIES})

    if(UNIX)
        find_package(LZMA REQUIRED)
        target_link_libraries(${PROJECT_NAME} ${LZMA_LIBRARIES})
    endif()

    # notify cmake about static build
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_SEARCH_START_STATIC ON)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_SEARCH_END_STATIC ON)

    # notify source code about static build
    remove_definitions(-D__STATIC__)
    add_definitions(-D__STATIC__)
endif()

set(SQL_DRIVERS 0)

if(USE_SQLITE)
    MATH(EXPR SQL_DRIVERS "${SQL_DRIVERS}+1")
    add_definitions(-D__USE_SQLITE__)
    find_package(SQLite3 CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} SQLite::SQLite3)
endif ()

if(USE_MYSQL)
    MATH(EXPR SQL_DRIVERS "${SQL_DRIVERS}+1")
    add_definitions(-D__USE_MYSQL__)
    find_package(libmysqlclient CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} libmysqlclient::libmysqlclient)
endif ()

if(USE_PGSQL)
    MATH(EXPR SQL_DRIVERS "${SQL_DRIVERS}+1")
    add_definitions(-D__USE_PGSQL__)
    find_package(PostgreSQL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PostgreSQL::PostgreSQL)
    list(APPEND ${OT_SOURCES} database/databasepgsql.cpp)
endif ()

if(USE_ODBC)
    MATH(EXPR SQL_DRIVERS "${SQL_DRIVERS}+1")
    add_definitions(-D__USE_ODBC__)
    find_package(unixodbc REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE UNIX::odbc)
endif ()

if (${SQL_DRIVERS} GREATER 1)
    add_definitions(-DMULTI_SQL_DRIVERS)
endif()

find_package(gmp)
target_link_libraries(${PROJECT_NAME} gmp::gmp)

if(UNIX)
    find_package(Threads)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} dl)
endif()

if(WIN32)
    target_link_libraries(${PROJECT_NAME} ws2_32 mswsock)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${LIBXML2_INCLUDE_DIRS})