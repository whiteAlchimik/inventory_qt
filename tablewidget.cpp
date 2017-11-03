#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    this->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);

    this->setShowGrid(true);

    this->setColumnCount(TABLE_COLUMNS);

    this->setRowCount(TABLE_ROWS);

    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

TableWidget::~TableWidget()
{}
