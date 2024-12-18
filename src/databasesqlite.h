////////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////

#ifndef __DATABASE_SQLITE__
#define __DATABASE_SQLITE__


#include "database.h"

#include <sqlite3.h>
#include <map>

class DatabaseSQLite: public Database
{
public:
    DatabaseSQLite();
    DATABASE_VIRTUAL ~DatabaseSQLite()
    {
        sqlite3_close(m_handle);
    }

    DATABASE_VIRTUAL bool getParam(DBParam_t param);

    DATABASE_VIRTUAL bool beginTransaction()
    {
        return executeQuery("BEGIN");
    }

    DATABASE_VIRTUAL bool rollback()
    {
        return executeQuery("ROLLBACK");
    }

    DATABASE_VIRTUAL bool commit()
    {
        return executeQuery("COMMIT");
    }

    DATABASE_VIRTUAL bool executeQuery(const std::string &query);
    DATABASE_VIRTUAL DBResult *storeQuery(const std::string &query);

    DATABASE_VIRTUAL std::string escapeString(const std::string &s);
    DATABASE_VIRTUAL std::string escapeBlob(const char *s, uint32_t length);

    DATABASE_VIRTUAL uint64_t getLastInsertId()
    {
        return (uint64_t)sqlite3_last_insert_rowid(m_handle);
    }

    DATABASE_VIRTUAL std::string getStringComparison()
    {
        return "LIKE ";
    }

    DATABASE_VIRTUAL std::string getUpdateLimiter()
    {
        return ";";
    }

    DATABASE_VIRTUAL DatabaseEngine_t getDatabaseEngine()
    {
        return DATABASE_ENGINE_SQLITE;
    }

protected:
    boost::recursive_mutex sqliteLock;

    std::string _parse(const std::string &s);
    sqlite3 *m_handle;
};

class SQLiteResult: public DBResult
{
    friend class DatabaseSQLite;

public:
    DATABASE_VIRTUAL int32_t getDataInt(const std::string &s);
    DATABASE_VIRTUAL int64_t getDataLong(const std::string &s);
    DATABASE_VIRTUAL std::string getDataString(const std::string &s);
    DATABASE_VIRTUAL const char *getDataStream(const std::string &s, uint64_t &size);

    DATABASE_VIRTUAL void free();
    DATABASE_VIRTUAL bool next()
    {
        return sqlite3_step(m_handle) == SQLITE_ROW;
    }

protected:
    SQLiteResult(sqlite3_stmt *stmt);
    DATABASE_VIRTUAL ~SQLiteResult() {}

    typedef std::map<const std::string, uint32_t> listNames_t;
    listNames_t m_listNames;

    sqlite3_stmt *m_handle;
};
#endif