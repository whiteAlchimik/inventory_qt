#ifndef INVENTORYCELLMAPPER_H
#define INVENTORYCELLMAPPER_H

#include <QSqlQuery>
#include <QSqlError>

#include "inventorycell.h"
#include "subjectmapper.h"

#include <QDebug>

#define CELL_TABLE "CellTable"
#define CELL_ROW "Row"
#define CELL_COLUMN "Column"
#define CELL_NUMBER_SUBJECTS "NumberSubjects"
#define CELL_SUBJECT_TYPE "SubjectType"

class InventoryCellMapper
{
public:
    InventoryCellMapper();

    static bool createTable();

    /*
     * Clears CELL_TABLE in the database.
     * Return values: true if OK,
     *                false if this failed for some reason.
     */
    static bool clearTable();

private:
    SubjectMapper _subjectMapper;
};

#endif // INVENTORYCELLMAPPER_H
