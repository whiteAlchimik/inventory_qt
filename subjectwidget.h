#ifndef SUBJECTWIDGET_H
#define SUBJECTWIDGET_H

#include <QWidget>

#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QIODevice>
#include <QDataStream>
#include "subject.h"

#include <QDebug>

class SubjectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubjectWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void setSubject(Subject *ptrSubject);

    ~SubjectWidget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QImage _image;

    Subject *_ptrSubject;

    QPoint _dragStartPosition;

    const int WIDGET_WIDTH = 150;
    const int WIDGET_HEIGHT = 150;
};

#endif // SUBJECTWIDGET_H
