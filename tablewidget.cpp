#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    this->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);
}

TableWidget::~TableWidget()
{}
