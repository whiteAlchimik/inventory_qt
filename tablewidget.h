#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include<QTableWidget>
#include <QHeaderView>

class TableWidget : public QTableWidget
{
public:
    TableWidget(QWidget *parent = nullptr);

    ~TableWidget();

private:
    const int WIDGET_WIDTH = 450;
    const int WIDGET_HEIGHT = 450;

    const int TABLE_COLUMNS = 3;
    const int TABLE_ROWS = 3;
};

#endif // TABLEWIDGET_H
