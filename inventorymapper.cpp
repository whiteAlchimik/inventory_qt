#include "inventorymapper.h"

InventoryMapper::InventoryMapper()
{

}

bool InventoryMapper::createTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("CREATE TABLE " INVENTORY_TABLE " ("
                    INVENTORY_ID " INTEGER PRIMARY KEY NOT NULL, "
                    INVENTORY_ROWS " INTEGER NOT NULL, "
                    INVENTORY_COLUMNS " INTEGER NOT NULL)");

    if(ok == false)
    {
        qDebug() << "DataBase: error of create " << CELL_TABLE;
        qDebug() << query.lastError().text();
    }

    return ok;
}

bool InventoryMapper::clearTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("DELETE FROM " INVENTORY_TABLE);

    return ok;
}
