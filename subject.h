#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QDataStream>

class Subject
{
public:

    enum SUBJECT_TYPE : qint16 {UNDEFINED, APPLE};
    static const QString mimeType;

    explicit Subject();

    explicit Subject(const SUBJECT_TYPE subjectType,
                     const QString &pathImage);

    /*
     * Copy constructor.
     */
    Subject(const Subject &subject);

    /*
     * Copy assignment operator.
     */
    Subject & operator=(const Subject &subject);

    SUBJECT_TYPE getSubjectType() const;
    void setSubjectType(const SUBJECT_TYPE &subjectType);

    QString getPathImage() const;
    void setPathImage(const QString &pathImage);

    bool operator==(const Subject &subject);

    void clear();

    friend QDataStream & operator<<(QDataStream &out, const Subject &subject);
    friend QDataStream & operator>>(QDataStream &in, Subject &subject);

    ~Subject();

private:
    SUBJECT_TYPE _subjectType;
    QString _pathImage;
};

#endif // SUBJECT_H
