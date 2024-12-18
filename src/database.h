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
#include "otsystem.h"

#include "enums.h"
#include <sstream>

#ifdef MULTI_SQL_DRIVERS
#define DATABASE_VIRTUAL virtual
#define DATABASE_CLASS _Database
#define DBRES_CLASS _DBResult
#else
#define DATABASE_VIRTUAL

#if defined(__USE_MYSQL__)
#define DATABASE_CLASS DatabaseMySQL
#define DBRES_CLASS MySQLResult
class DatabaseMySQL;
class MySQLResult;

#elif defined(__USE_SQLITE__)
#define DATABASE_CLASS DatabaseSQLite
#define DBRES_CLASS SQLiteResult
class DatabaseSQLite;
class SQLiteResult;

#elif defined(__USE_ODBC__)
#define DATABASE_CLASS DatabaseODBC
#define DBRES_CLASS ODBCResult
class DatabaseODBC;
class ODBCResult;

#elif defined(__USE_PGSQL__)
#define DATABASE_CLASS DatabasePgSQL
#define DBRES_CLASS PgSQLResult
class DatabasePgSQL;
class PgSQLResult;

#endif
#endif

#ifndef DATABASE_CLASS
#error "You have to compile with at least one database driver!"
#define DBResult void
#define DBInsert void*
#define Database void
#else

class DBQuery;
class DBResult;

enum DBParam_t
{
    DBPARAM_MULTIINSERT = 1
};

class Database
{
public:
    /**
    * Singleton implementation.
    *
    * Returns instance of database handler. Don't create database (or drivers) instances in your code - instead of it use Database::getInstance()-> This method stores static instance of connection class internaly to make sure exacly one instance of connection is created for entire system.
    *
    * @return database connection handler singleton
    */
    static boost::shared_ptr<Database> getInstance();

    /**
    * Database information.
    *
    * Returns currently used database attribute.
    *
    * @param param parameter to get
    * @return suitable for given parameter
    */
    DATABASE_VIRTUAL bool getParam(DBParam_t param) { return false; }

    /**
    * Database connected.
    *
    * Returns whether the database is connected.
    *
    * @return whether the database is connected.
    */
    DATABASE_VIRTUAL bool isConnected() { return m_connected; }

    /**
    * Database ...
    */
    DATABASE_VIRTUAL void use() { m_use = time(nullptr); }

protected:
    /**
    * Transaction related methods.
    *
    * Methods for starting, commiting and rolling back transaction. Each of the returns boolean value.
    *
    * @return true on success, false on error
    * @note
    *	If your database system doesn't support transactions you should return true - it's not feature test, code should work without transaction, just will lack integrity.
    */
    friend class DBTransaction;

    DATABASE_VIRTUAL bool beginTransaction() { return false; }
    DATABASE_VIRTUAL bool rollback() { return false; }
    DATABASE_VIRTUAL bool commit() { return false; }

public:
    /**
    * Executes command.
    *
    * Executes query which doesn't generate results (e.g. INSERT, UPDATE, DELETE...).
    *
    * @param query  query command
    * @return true on success, false on error
    */
    DATABASE_VIRTUAL bool executeQuery(const std::string& query) { return false; }

    /**
    * Queries database.
    *
    * Executes query which generates results (mostly SELECT).
    *
    * @param query query command
    * @return results object (null on error)
    */
    DATABASE_VIRTUAL DBResult* storeQuery(const std::string& query) { return nullptr; }

    /**
    * Escapes string for query.
    *
    * Prepares string to fit SQL queries including quoting it.
    *
    * @param s std::string string to be escaped
    * @return quoted string
    */
    DATABASE_VIRTUAL std::string escapeString(const std::string& s) { return "''"; }

    /**
    * Escapes binary stream for query.
    *
    * Prepares binary stream to fit SQL queries.
    *
    * @param s char* binary stream
    * @param length long stream length
    * @return quoted string
    */
    DATABASE_VIRTUAL std::string escapeBlob(const char* s, uint32_t length) { return "''"; }

    /**
     * Retrieve id of last inserted row
     *
     * @return id on success, 0 if last query did not result on any rows with auto_increment keys
     */
    DATABASE_VIRTUAL uint64_t getLastInsertId() { return 0; }

    /**
    * Get case insensitive string comparison operator
    *
    * @return the case insensitive operator
    */
    DATABASE_VIRTUAL std::string getStringComparison() { return "= "; }
    DATABASE_VIRTUAL std::string getUpdateLimiter() { return " LIMIT 1;"; }

    /**
    * Get database engine
    *
    * @return the database engine type
    */
    DATABASE_VIRTUAL DatabaseEngine_t getDatabaseEngine() { return DATABASE_ENGINE_NONE; }

protected:
    Database(): m_connected(false), m_use(0)
    {
    }

    DATABASE_VIRTUAL ~Database() = default;

    static DBResult* verifyResult(DBResult* result);

    bool m_connected;
    time_t m_use;
};

class DBResult
{
public:
    /** Get the Integer value of a field in database
    *\returns The Integer value of the selected field and row
    *\param s The name of the field
    */
    DATABASE_VIRTUAL int32_t getDataInt(const std::string& s) { return 0; }

    /** Get the Long value of a field in database
    *\returns The Long value of the selected field and row
    *\param s The name of the field
    */
    DATABASE_VIRTUAL int64_t getDataLong(const std::string& s) { return 0; }

    /** Get the String of a field in database
    *\returns The String of the selected field and row
    *\param s The name of the field
    */
    DATABASE_VIRTUAL std::string getDataString(const std::string& s) { return "''"; }

    /** Get the blob of a field in database
    *\returns a PropStream that is initiated with the blob data field, if not exist it returns NULL.
    *\param s The name of the field
    */
    DATABASE_VIRTUAL const char* getDataStream(const std::string& s, uint64_t& size) { return nullptr; }

    /** Result freeing
    */
    DATABASE_VIRTUAL void free()
    {
        /*delete this;*/
    }

    /** Moves to next result in set
    *\returns true if moved, false if there are no more results.
    */
    DATABASE_VIRTUAL bool next() { return false; }

protected:
    DBResult()
    {
    }

    DATABASE_VIRTUAL ~DBResult() = default;
};

/**
 * Thread locking hack.
 *
 * By using this class for your queries you lock and unlock database for threads.
*/
class DBQuery : public std::stringstream
{
    friend class Database;

public:
    DBQuery() { databaseLock.lock(); }

    ~DBQuery() override
    {
        str("");
        databaseLock.unlock();
    }

protected:
    static boost::recursive_mutex databaseLock;
};

/**
 * INSERT statement.
 *
 * Gives possibility to optimize multiple INSERTs on databases that support multiline INSERTs.
 */
class DBInsert
{
public:
    /**
    * Associates with given database handler.
    *
    * @param db boost::shared_ptr<Database> database wrapper
    */
    explicit DBInsert(const boost::shared_ptr<Database>& db);

    virtual ~DBInsert() = default;

    /**
    * Sets query prototype.
    *
    * @param query std::string& INSERT query
    */
    void setQuery(const std::string& query);

    /**
    * Adds new row to INSERT statement.
    *
    * On databases that doesn't support multiline INSERTs it simply execute INSERT for each row.
    *
    * @param row  row data
    */
    bool addRow(const std::string& row);
    /**
    * Allows to use addRow() with stringstream as parameter.
    */
    bool addRow(std::stringstream& row);

    /**
    * Executes current buffer.
    */
    bool execute();

protected:
    boost::shared_ptr<Database> m_db;
    bool m_multiLine;

    uint32_t m_rows;
    std::string m_query, m_buf;
};


#ifndef MULTI_SQL_DRIVERS
#if defined(__USE_MYSQL__)
#include "database/databasemysql.h"
#elif defined(__USE_SQLITE__)
#include "databasesqlite.h"
#elif defined(__USE_ODBC__)
#include "databaseodbc.h"
#elif defined(__USE_PGSQL__)
#include "databasepgsql.h"
#endif
#endif

class DBTransaction final
{
public:
    explicit DBTransaction(const boost::shared_ptr<Database>& database)
    {
        m_database = database;
        m_state = STATE_NO_START;
    }

    ~DBTransaction()
    {
        if (m_state == STATE_START)
            m_database->rollback();
    }

    bool begin()
    {
        m_state = STATE_START;
        return m_database->beginTransaction();
    }

    bool commit()
    {
        if (m_state != STATE_START)
            return false;

        m_state = STEATE_COMMIT;
        return m_database->commit();
    }

private:
    boost::shared_ptr<Database> m_database;

    enum TransactionStates_t
    {
        STATE_NO_START,
        STATE_START,
        STEATE_COMMIT
    };

    TransactionStates_t m_state;
};
#endif
