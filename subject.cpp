#include "subject.h"

const QString Subject::mimeType = "data/subject";

Subject::Subject() :
    _subjectType(Subject::UNDEFINED),
    _pathImage("")
{}

Subject::Subject(const SUBJECT_TYPE subjectType,
                 const QString &pathImage) :
    _subjectType(subjectType),
    _pathImage(pathImage)
{}

Subject::Subject(const Subject &subject) :
    _subjectType(subject._subjectType),
    _pathImage(subject._pathImage)
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

Subject::SUBJECT_TYPE Subject::getSubjectType() const
{
    return _subjectType;
}

void Subject::setSubjectType(const SUBJECT_TYPE &subjectType)
{
    _subjectType = subjectType;
}

QString Subject::getPathImage() const
{
    return _pathImage;
}

void Subject::setPathImage(const QString &pathImage)
{
    _pathImage = pathImage;
}

QDataStream & operator<<(QDataStream &out, const Subject &subject)
{
    out << static_cast<qint16>(subject._subjectType) << subject._pathImage;
    return out;
}

QDataStream & operator>>(QDataStream &in, Subject &subject)
{
    qint16 temp;
    in >> temp;
    subject._subjectType = static_cast<Subject::SUBJECT_TYPE>(temp);
    in >> subject._pathImage;
    return in;
}

Subject::~Subject()
{}
