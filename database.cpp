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

void DataBase::saveInventoryToDataBase(const Inventory &inventory)
{
    InventoryMapper::save(inventory);
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
