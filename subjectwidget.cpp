#include "subjectwidget.h"

SubjectWidget::SubjectWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(150, 150);
}

void SubjectWidget::paintEvent(QPaintEvent *event)
{
    QImage image(":/resources/images/image_apple.jpg");

    QPainter painter(this);

    painter.drawImage(0, 0, image);

    QWidget::paintEvent(event);
}
