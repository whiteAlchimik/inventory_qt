#include "database.h"

DataBase::DataBase(QObject *parent) :
    QObject(parent)
{}

void DataBase::connectToDataBase()
{
    if(QFile(DATABASE_NAME).exists())
    {
       this->openDataBase();
    }
    else
    {
        this->restoreDataBase();
    }
}

bool DataBase::openDataBase()
{
    _dataBase = QSqlDatabase::addDatabase("QSQLITE");
    _dataBase.setHostName(DATABASE_HOSTNAME);
    _dataBase.setDatabaseName(DATABASE_NAME);
    bool ok = _dataBase.open();

    return ok;
}

void DataBase::closeDataBase()
{
    _dataBase.close();
}

bool DataBase::restoreDataBase()
{
    bool ok = false;

    if(this->openDataBase())
    {
        ok = this->createTables();
    }
    else
    {
        qDebug() << "restoreDataBase error";
    }

    return ok;
}

bool DataBase::createTables()
{
    bool ok;

    ok = InventoryMapper::createTable();
    ok = ok && InventoryCellMapper::createTable();
    ok = ok && SubjectMapper::createTable();

    return ok;
}

bool DataBase::clearTables()
{
    bool ok;

    ok = InventoryMapper::clearTable();
    ok = ok && InventoryCellMapper::clearTable();
    ok = ok && SubjectMapper::clearTable();

    return ok;
}

/*
bool DataBase::insertIntoSubjectTable(const QVariantList &data)
{
    if(data.isEmpty())
    {
        return false;
    }

    bool ok = false;
    QSqlQuery query;

    query.prepare("INSERT INTO " SUBJECT_TABLE " (" SUBJECT_TABLE_SERIALIZATION_ID ", "
                  SUBJECT_TABLE_TYPE ", "
                  SUBJECT_TABLE_PATH ") "
                                     "VALUES (?, ?, ?)");
    query.bindValue(0, data[0].toString());
    query.bindValue(1, data[1].toString());
    query.bindValue(2, data[2].toString());
    ok = query.exec();

    if(ok == false)
    {
        qDebug() << "DataBase: error of create " << SUBJECT_TABLE;
        qDebug() << query.lastError().text();
    }

    return ok;
}
*/
