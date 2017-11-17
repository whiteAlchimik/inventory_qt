
#include "subjectfactory.h"

#include "subject.h"
#include "subjectapple.h"

SubjectFactory::SubjectFactory()
{
    this->add<SubjectApple>(SubjectApple::SERIALIZATION_ID);
}

Subject *SubjectFactory::create(const QString &id)
{
    if(_types.contains(id) == false)
    {
        return nullptr;
    }

    return _types.value(id)->create();
}
SubjectFactory::~SubjectFactory()
{
    QHash<QString, AbstractSubjectCreator *>::iterator it = _types.begin();
    while(it != _types.end())
    {
        delete it.value();
        it++;
    }
}

template < typename T >
void SubjectFactory::add(const QString &id)
{
    if(_types.contains(id) == false)
    {
        _types.insert(id, new SubjectCreator<T>());
    }
}
