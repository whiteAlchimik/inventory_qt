#ifndef SUBJECTMAPPER_H
#define SUBJECTMAPPER_H

#include <QSqlQuery>
#include <QSqlError>

#include "subject.h"

#include <QDebug>

#define SUBJECT_TABLE "SubjectTable"
#define SUBJECT_ID "Id"
#define SUBJECT_TYPE "Type"
#define SUBJECT_PATH "Path"

class SubjectMapper
{
public:
    explicit SubjectMapper();

    static bool createTable();

    /*
     * Clears SUBJECT_TABLE in the database.
     * Return values: true if OK,
     *                false if this failed for some reason.
     */
    static bool clearTable();

    static bool save(const Subject &subject);
};

#endif // SUBJECTMAPPER_H
