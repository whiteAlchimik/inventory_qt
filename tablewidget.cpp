#include "tablewidget.h"

TableWidget::TableWidget(int rows,
                         int columns,
                         QWidget *parent) :
    QTableWidget(rows, columns, parent)
{
    this->setAcceptDrops(true);

    this->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);

    this->setShowGrid(true);

    this->setSelectionMode(QAbstractItemView::SingleSelection);

    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setIconSize(QSize(ICON_WIDTH, ICON_HEIGHT));
}

TableWidget::~TableWidget()
{}

void TableWidget::slotUpdateValueInCell(const int newValue, const int row, const int column)
{
    if((row >= this->rowCount() || row < 0) ||
            (column >= this->colorCount() || column < 0))
        return;

    if(this->item(row, column) != nullptr)
    {
        this->item(row, column)->setText(QString::number(newValue));
    }
}

void TableWidget::addItem(const int row, const int column, const QString pathImage)
{
    if((row >= this->rowCount() || row < 0) ||
            (column >= this->colorCount() || column < 0))
        return;

    /*if(this->item(row, column) != nullptr)
        return;

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setIcon(QIcon(QPixmap(pathImage)));
    item->setTextAlignment(Qt::AlignBottom | Qt::AlignRight);
    this->setItem(row, column, item);*/
}

void TableWidget::removeItem(const int row, const int column)
{
    if((row >= this->rowCount() || row < 0) ||
            (column >= this->colorCount() || column < 0))
        return;

    QTableWidgetItem *item = this->item(row, column);
    this->takeItem(row, column);
    delete item;
}

void TableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat(Subject::mimeType))
    {
        event->acceptProposedAction();
    }
}

void TableWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

void TableWidget::dropEvent(QDropEvent *event)
{
    QTableWidget::dropEvent(event);

    QByteArray in;
    in = event->mimeData()->data(Subject::mimeType);
    QDataStream dataStream(&in, QIODevice::ReadOnly);
    Subject subject;
    dataStream >> subject;
    int row = this->indexAt(event->pos()).row();
    int column = this->indexAt(event->pos()).column();

    this->addItem(row, column, subject.getPathImage());

    //emit insertSubject(row, column, subject);
}
