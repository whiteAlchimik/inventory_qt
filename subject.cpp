#include "subject.h"

Subject::Subject(const SUBJECT_TYPE subjectType,
                 const QString &pathImage) :
    _subjectType(subjectType),
    _pathImage(pathImage)
{}

Subject::~Subject()
{}
