#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QByteArray>
#include <QDataStream>
#include <QVariantList>

#include "subjectfactory.h"

class Subject
{
public:
    static const QString mimeType;

    Subject();

    Subject(const QString &subjectType,
            const QString &pathImage);

    Subject & operator=(const Subject &subject);

    QString subjectType() const;

    QString pathImage() const;

    virtual QString serializationId() const = 0;

    virtual bool cmp(const Subject *ptrSubject) const = 0;

    virtual Subject * clone() const = 0;

    virtual QVariantList prepareDataForDataBase() const = 0;

    friend QDataStream & operator<<(QDataStream &out, const Subject &subject);

    friend QDataStream & operator>>(QDataStream &in, Subject &subject);

    static QByteArray serialize(const Subject *ptrSubject);

    static Subject * deserialize(QByteArray &byteArray);

    virtual ~Subject() {}

protected:
    virtual void qDataStreamWrite(QDataStream &out) const = 0;
    virtual void qDataStreamRead(QDataStream &in) = 0;

private:
    QString _subjectType;
    QString _pathImage;
};

#endif // SUBJECT_H
