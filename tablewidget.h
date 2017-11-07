#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include<QTableWidget>
#include <QHeaderView>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include <QString>
#include <QPoint>

#include "subjectwidget.h"

#include <QDebug>

class TableWidget : public QTableWidget
{

    Q_OBJECT

public:
    TableWidget(int rows,
                int columns,
                QWidget *parent = nullptr);

    ~TableWidget();

signals:
    void insertSubject(const int row,
                       const int column,
                       const Subject &subject,
                       const int subjectCount = 1);

    void removeSubject(const int row,
                       const int column,
                       const int subjectCount = 1);

public slots:
    void slotUpdateValueInCell(const int newValue,
                               const int row,
                               const int column);

    void addItem(const int row,
                 const int column,
                 const QString pathImage);

    void removeItem(const int row,
                    const int column);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint _dragStartPosition;

    const int WIDGET_WIDTH = 450;
    const int WIDGET_HEIGHT = 450;

    const int ICON_WIDTH = 130;
    const int ICON_HEIGHT = 130;
};

#endif // TABLEWIDGET_H
