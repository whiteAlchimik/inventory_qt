#ifndef SUBJECTFACTORY_H
#define SUBJECTFACTORY_H

#include <QString>
#include <QHash>

class Subject;

class AbstractSubjectCreator
{
public:
    virtual Subject * create() const = 0;
    virtual ~AbstractSubjectCreator() {}
};

template < typename T >
class SubjectCreator : public AbstractSubjectCreator
{
public:
    virtual Subject * create() const
    {
        return new T();
    }
};

class SubjectFactory
{
public:
    SubjectFactory();

    Subject * create(const QString &id);

    ~SubjectFactory();

private:
    QHash<QString, AbstractSubjectCreator *> _types;

    template < typename T >
    void add(const QString &id);

    SubjectFactory(const SubjectFactory &);
    SubjectFactory & operator=(const SubjectFactory &);
};

class SinglentonSubjectFactory
{
public:
    static SubjectFactory & getInstance()
    {
        static SubjectFactory subjectFactory;
        return subjectFactory;
    }

private:
    SinglentonSubjectFactory();
    SinglentonSubjectFactory(const SinglentonSubjectFactory &);
    SinglentonSubjectFactory & operator=(const SinglentonSubjectFactory &);
};

#endif // SUBJECTFACTORY_H
