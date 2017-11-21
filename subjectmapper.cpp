#include "subjectmapper.h"

SubjectMapper::SubjectMapper()
{}

bool SubjectMapper::createTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("CREATE TABLE " SUBJECT_TABLE " ("
                    SUBJECT_ID " VARCHAR(255) PRIMARY KEY NOT NULL, "
                    SUBJECT_TYPE " VARCHAR(255) NOT NULL, "
                    SUBJECT_PATH " VARCHAR(255) NOT NULL )");

    if(ok == false)
    {
        qDebug() << "DataBase: error of create " << SUBJECT_TABLE;
        qDebug() << query.lastError().text();
    }

    return ok;
}

bool SubjectMapper::clearTable()
{
    bool ok = false;
    QSqlQuery query;

    ok = query.exec("DELETE FROM " SUBJECT_TABLE);

    return ok;
}

bool SubjectMapper::save(const Subject &subject)
{
    bool ok = false;

    return ok;
}
