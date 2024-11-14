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

#pragma once

#include "database.h"
#include <libpq-fe.h>

class DatabasePgSQL final: public Database
{
public:
    DatabasePgSQL();

    ~DatabasePgSQL() override
    {
        PQfinish(m_handle);
    }

    bool getParam(DBParam_t param) override;

    bool beginTransaction() override
    {
        return executeQuery("BEGIN");
    }

    bool rollback() override
    {
        return executeQuery("ROLLBACK");
    }

    bool commit() override
    {
        return executeQuery("COMMIT");
    }

    bool executeQuery(const std::string &query) override;
    DBResult *storeQuery(const std::string &query) override;

    std::string getUpdateLimiter() override
    {
        return ";";
    }

    std::string escapeString(const std::string &s) override;
    std::string escapeBlob(const char *s, uint32_t length) override;

    uint64_t getLastInsertId() override;

    DatabaseEngine_t getDatabaseEngine() override
    {
        return DATABASE_ENGINE_POSTGRESQL;
    }

protected:
    std::string _parse(const std::string &s);
    PGconn *m_handle;
};

class PgSQLResult final: public DBResult
{
    friend class DatabasePgSQL;

public:
    int32_t getDataInt(const std::string &s) override
    {
        return atoi(
            PQgetvalue(m_handle, m_cursor, PQfnumber(m_handle, s.c_str())));
    }

    int64_t getDataLong(const std::string &s) override
    {
        return atoll(
            PQgetvalue(m_handle, m_cursor, PQfnumber(m_handle, s.c_str())));
    }

    std::string getDataString(const std::string &s) override
    {
        return
            PQgetvalue(m_handle, m_cursor, PQfnumber(m_handle, s.c_str()));
    }

    const char *getDataStream(const std::string &s, uint64_t &size) override;

    void free() override;
    bool next() override;

protected:
    PgSQLResult(PGresult *results);

    ~PgSQLResult() override = default;

    PGresult *m_handle;
    int32_t m_rows, m_cursor;
};