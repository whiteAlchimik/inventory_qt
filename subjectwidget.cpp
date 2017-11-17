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
    _image.load(_ptrSubject->pathImage());
    this->update();
}

void SubjectWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        _dragStartPosition = event->pos();
}

void SubjectWidget::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) &&
            ((event->pos() - _dragStartPosition).manhattanLength() <
             QApplication::startDragDistance()))
    {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        QByteArray byteArray = Subject::serialize(_ptrSubject);

        mimeData->setData(_ptrSubject->mimeType, byteArray);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap::fromImage(_image).scaled(WIDGET_WIDTH, WIDGET_HEIGHT));
        drag->setHotSpot(QPoint(WIDGET_WIDTH / 2, WIDGET_HEIGHT / 2));
        Qt::DropAction dropAction = drag->exec(Qt::CopyAction);
    }

    return QWidget::mouseMoveEvent(event);
}
