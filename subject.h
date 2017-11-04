#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QDataStream>

class Subject
{
public:

    enum SUBJECT_TYPE : qint16 {APPLE};

    explicit Subject(const SUBJECT_TYPE subjectType,
                     const QString &pathImage);

    ~Subject();

    QString getPathImage() const;

    static const QString mimeType;

    friend QDataStream & operator<<(QDataStream &out, const Subject &subject);
    friend QDataStream & operator>>(QDataStream &in, Subject &subject);
private:
    SUBJECT_TYPE _subjectType;
    QString _pathImage;
};

#endif // SUBJECT_H
