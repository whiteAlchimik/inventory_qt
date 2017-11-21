#include "subjectapple.h"

const QString SubjectApple::SERIALIZATION_ID = "SubjectApple";

SubjectApple::SubjectApple(const QString subjectType,
                           const QString pathImage) :
    Subject(subjectType, pathImage)
{}

SubjectApple::SubjectApple(const SubjectApple &subjectApple) :
    Subject(subjectApple.subjectType(), subjectApple.pathImage())
{}

SubjectApple &SubjectApple::operator=(const SubjectApple &subjectApple)
{
    if(this != &subjectApple)
    {
        *((Subject *)this) = subjectApple;
    }
    return *this;
}

QString SubjectApple::serializationId() const
{
    return SERIALIZATION_ID;
}

bool SubjectApple::cmp(const Subject *ptrSubject) const
{
    if(ptrSubject == nullptr)
        return false;

    return (typeid(*this) == typeid(*ptrSubject));
}

Subject *SubjectApple::clone() const
{
    return new SubjectApple();
}

QVariantList SubjectApple::prepareDataForDataBase() const
{
    QVariantList data;

    data.append(SERIALIZATION_ID);
    data.append(this->subjectType());
    data.append(this->pathImage());

    return data;
}

void SubjectApple::qDataStreamWrite(QDataStream &out) const
{
    Subject::qDataStreamWrite(out);
}

void SubjectApple::qDataStreamRead(QDataStream &in)
{
    Subject::qDataStreamRead(in);
}
