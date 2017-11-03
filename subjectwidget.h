#ifndef SUBJECTWIDGET_H
#define SUBJECTWIDGET_H

#include <QWidget>

#include <QImage>
#include <QPainter>

#include "subject.h"

class SubjectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubjectWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void setSubject(Subject *ptrSubject);

    ~SubjectWidget();

private:
    QImage _image;

    Subject *_ptrSubject;

    const int WIDGET_WIDTH = 150;
    const int WIDGET_HEIGHT = 150;
};

#endif // SUBJECTWIDGET_H
