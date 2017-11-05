#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include<QTableWidget>
#include <QHeaderView>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include "subjectwidget.h"

#include <QDebug>

class TableWidget : public QTableWidget
{
public:
    TableWidget(QWidget *parent = nullptr);

    ~TableWidget();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    const int WIDGET_WIDTH = 450;
    const int WIDGET_HEIGHT = 450;

    const int TABLE_COLUMNS = 3;
    const int TABLE_ROWS = 3;
};

#endif // TABLEWIDGET_H
