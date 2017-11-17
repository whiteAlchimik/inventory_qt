#include "subject.h"

const QString Subject::mimeType = "data/subject";

Subject::Subject() :
    _subjectType(""),
    _pathImage("")
{}

Subject::Subject(const QString &subjectType,
                 const QString &pathImage) :
    _subjectType(subjectType),
    _pathImage(pathImage)
{}

Subject &Subject::operator=(const Subject &subject)
{
    if(this != &subject)
    {
        _subjectType = subject._subjectType;
        _pathImage = subject._pathImage;
    }
    return *this;
}

QString Subject::subjectType() const
{
    return _subjectType;
}

QString Subject::pathImage() const
{
    return _pathImage;
}

QDataStream & operator<<(QDataStream &out, const Subject &subject)
{
    subject.qDataStreamWrite(out);
    return out;
}

QDataStream & operator>>(QDataStream &in, Subject &subject)
{
    subject.qDataStreamRead(in);
    return in;
}

QByteArray Subject::serialize(const Subject *ptrSubject)
{
    if(ptrSubject == nullptr)
    {
        return QByteArray();
    }

    QByteArray byteArray;
    QDataStream dataStream(&byteArray, QIODevice::WriteOnly);

    dataStream << ptrSubject->serializationId();
    dataStream << *(ptrSubject);

    return byteArray;
}

Subject *Subject::deserialize(QByteArray &byteArray)
{
    if(byteArray.isEmpty())
    {
        return nullptr;
    }

    QDataStream dataStream(&byteArray, QIODevice::ReadOnly);
    QString serializationId;
    dataStream >> serializationId;

    Subject *ptr = SinglentonSubjectFactory::getInstance().create(serializationId);
    dataStream >> *(ptr);

    return ptr;
}

void Subject::qDataStreamWrite(QDataStream &out) const
{
    out << _subjectType;
    out << _pathImage;
}

void Subject::qDataStreamRead(QDataStream &in)
{
    in >> _subjectType;
    in >> _pathImage;
}
