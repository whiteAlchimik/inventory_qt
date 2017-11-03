#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>

class Subject
{
public:

    enum SUBJECT_TYPE {APPLE};

    explicit Subject(const SUBJECT_TYPE subjectType,
                     const QString &pathImage);

    ~Subject();

private:
    SUBJECT_TYPE _subjectType;
    QString _pathImage;
};

#endif // SUBJECT_H
