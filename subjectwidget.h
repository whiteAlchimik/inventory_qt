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
};

#endif // SUBJECTWIDGET_H
