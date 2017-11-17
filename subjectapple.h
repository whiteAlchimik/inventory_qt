#ifndef SUBJECTAPPLE_H
#define SUBJECTAPPLE_H

#include <QDebug>

#include "subject.h"

#define SUBJECT_TYPE "Apple"
#define PATH_IMAGE ":/resources/images/image_apple.jpg"

class SubjectApple : public Subject
{
public:
    static const QString SERIALIZATION_ID;

    SubjectApple(const QString subjectType = SUBJECT_TYPE,
                 const QString pathImage = PATH_IMAGE);

    SubjectApple(const SubjectApple &subjectApple);

    SubjectApple & operator=(const SubjectApple &subjectApple);

    QString serializationId() const;

    bool cmp(const Subject *ptrSubject) const;

    Subject * clone() const;

    ~SubjectApple() {}

protected:
    void qDataStreamWrite(QDataStream &out) const;
    void qDataStreamRead(QDataStream &in);
};

#endif // SUBJECTAPPLE_H
