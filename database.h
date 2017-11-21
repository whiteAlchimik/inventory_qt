#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QVariantList>

#include "inventorymapper.h"
#include "inventorycellmapper.h"
#include "subjectmapper.h"

#include <QDebug>

#define DATABASE_HOSTNAME "Host"
#define DATABASE_NAME "data_base.db"

class DataBase : public QObject
{

    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);

    void connectToDataBase();

    /*
     * Close database.
     */
    void closeDataBase();

    void saveInventoryToDataBase(const Inventory &inventory);

private:
    QSqlDatabase _dataBase;

    /*
     * Open database.
     * Return values: true if OK,
     *                false if this failed for some reason.
     */
    bool openDataBase();

    bool restoreDataBase();

    /*
     * Create INVENTORY_TABLE, CELL_TABLE, SUBJECT_TABLE.
     * Return values: true if OK,
     *                false if this failed for some reason.
     */
    bool createTables();

    /*
     * Clears INVENTORY_TABLE, CELL_TABLE, SUBJECT_TABLE.
     * Return values: true if OK,
     *                false if this failed for some reason.
     */
    bool clearTables();
};

#endif // DATABASE_H
