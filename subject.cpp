#include "subject.h"

const QString Subject::mimeType = "data/subject";

Subject::Subject(const SUBJECT_TYPE subjectType,
                 const QString &pathImage) :
    _subjectType(subjectType),
    _pathImage(pathImage)
{}

Subject::~Subject()
{}

QString Subject::getPathImage() const
{
    return _pathImage;
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
