#include "inventorycellmapper.h"

InventoryCellMapper::InventoryCellMapper()
{}

bool InventoryCellMapper::createTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("CREATE TABLE " CELL_TABLE " ("
                    CELL_ROW " INTEGER NOT NULL, "
                    CELL_COLUMN " INTEGER NOT NULL, "
                    CELL_NUMBER_SUBJECTS " INTEGER NOT NULL, "
                    CELL_SUBJECT_TYPE " VARCHAR(255) NOT NULL, "
                    "PRIMARY KEY (" CELL_ROW ", " CELL_COLUMN "), "
                    "FOREIGN KEY (" CELL_SUBJECT_TYPE ") REFERENCES "
                    SUBJECT_TABLE " (" SUBJECT_ID "))");

    if(ok == false)
    {
        qDebug() << "DataBase: error of create " << CELL_TABLE;
        qDebug() << query.lastError().text();
    }

    return ok;
}

bool InventoryCellMapper::clearTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("DELETE FROM " CELL_TABLE);

    return ok;
}
