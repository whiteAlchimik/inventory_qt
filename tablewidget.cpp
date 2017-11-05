#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    this->setAcceptDrops(true);

    this->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);

    this->setShowGrid(true);

    this->setColumnCount(TABLE_COLUMNS);

    this->setRowCount(TABLE_ROWS);

    this->setSelectionMode(QAbstractItemView::SingleSelection);

    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

TableWidget::~TableWidget()
{}

void TableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat(Subject::mimeType))
    {
        event->acceptProposedAction();
    }
}

void TableWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void TableWidget::dropEvent(QDropEvent *event)
{
    QByteArray in;
    in = event->mimeData()->data(Subject::mimeType);

    QDataStream dataStream(&in, QIODevice::ReadOnly);
}
