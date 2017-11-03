#include "subjectwidget.h"

SubjectWidget::SubjectWidget(QWidget *parent) :
    QWidget(parent),
    _ptrSubject(nullptr)
{
    this->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);
}

void SubjectWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawImage(0, 0, _image.scaled(this->size()));

    QWidget::paintEvent(event);
}

void SubjectWidget::setSubject(Subject *ptrSubject)
{
    _ptrSubject = ptrSubject;
    _image.load(_ptrSubject->getPathImage());
    this->update();
}

SubjectWidget::~SubjectWidget()
{}
