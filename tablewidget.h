#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include<QTableWidget>

class TableWidget : public QTableWidget
{
public:
    TableWidget(QWidget *parent = nullptr);

    ~TableWidget();

private:
    const int WIDGET_WIDTH = 450;
    const int WIDGET_HEIGHT = 450;
};

#endif // TABLEWIDGET_H
