#ifndef INVENTORYMAPPER_H
#define INVENTORYMAPPER_H

#include <QSqlQuery>
#include <QSqlError>

#include "inventorycellmapper.h"

#include <QDebug>

#define INVENTORY_TABLE "InventoryTable"
#define INVENTORY_ID "Id"
#define INVENTORY_ROWS "Rows"
#define INVENTORY_COLUMNS "Columns"

class InventoryMapper
{
public:
    InventoryMapper();

    static bool createTable();

    /*
     * Clears INVENTORY_TABLE in the database.
     * Return values: true if OK,
     *                false if this failed for some reason.
     */
    static bool clearTable();

private:
    InventoryCellMapper _inventoryCellMapper;
};

#endif // INVENTORYMAPPER_H
