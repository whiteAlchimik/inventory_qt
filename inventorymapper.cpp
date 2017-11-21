#include "inventorymapper.h"

InventoryMapper::InventoryMapper()
{

}

bool InventoryMapper::createTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("CREATE TABLE " INVENTORY_TABLE " ("
                    INVENTORY_ID " INTEGER PRIMARY KEY AUTOINCREMENT, "
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

bool InventoryMapper::save(const Inventory &inventory)
{
    bool ok = false;
    QSqlQuery query;

    query.prepare("INSERT INTO " INVENTORY_TABLE " ("
                  INVENTORY_ROWS ", "
                  INVENTORY_COLUMNS ") VALUES (?, ?)");

    query.addBindValue(inventory.rows());
    query.addBindValue(inventory.columns());

    ok = query.exec();

    if(ok != false)
    {
        for(int i = 0; i < inventory.rows(); i++)
        {
            for(int j = 0; j < inventory.columns(); j++)
            {
                InventoryCellMapper::save(inventory.inventoryCell(i, j), i, j);
            }
        }
    }

    return ok;
}
