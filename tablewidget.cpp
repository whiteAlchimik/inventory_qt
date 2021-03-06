#include "tablewidget.h"

TableWidget::TableWidget(int rows,
                         int columns,
                         QWidget *parent) :
    QTableWidget(rows, columns, parent)
{
    this->setAcceptDrops(true);

    this->setFixedSize(CELL_WIDTH * columns, CELL_HEIGHT * rows);

    this->setShowGrid(true);

    this->setSelectionMode(QAbstractItemView::NoSelection);

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
            (column >= this->columnCount() || column < 0))
    {
        return;
    }

    if(this->item(row, column) != nullptr)
    {
        this->item(row, column)->setText(QString::number(newValue));
    }
}

void TableWidget::addItem(const int row,
                          const int column,
                          const InventoryCell &inventoryCell)
{
    if((row >= this->rowCount() || row < 0) ||
            (column >= this->columnCount() || column < 0))
    {
        return;
    }

    if(this->item(row, column) != nullptr)
    {
        this->removeItem(row, column);
    }

    QTableWidgetItem *item = new QTableWidgetItem;

    item->setIcon(QIcon(QPixmap(inventoryCell.subject()->pathImage())));
    item->setTextAlignment(Qt::AlignBottom | Qt::AlignRight);
    item->setText(QString::number(inventoryCell.numberSubject()));
    this->setItem(row, column, item);
}

void TableWidget::removeItem(const int row, const int column)
{
    if((row >= this->rowCount() || row < 0) ||
            (column >= this->columnCount() || column < 0))
    {
        return;
    }

    if(this->item(row, column) != nullptr)
    {
        QTableWidgetItem *item = this->item(row, column);
        this->takeItem(row, column);
        delete item;
    }
}

void TableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat(Subject::mimeType))
    {
        event->acceptProposedAction();
    }
    else if(event->mimeData()->hasFormat(Inventory::mimeTypeForMove))
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
    if(event->mimeData()->hasFormat(Subject::mimeType))
    {
        int row = this->indexAt(event->pos()).row();
        int column = this->indexAt(event->pos()).column();

        QByteArray in;
        in = event->mimeData()->data(Subject::mimeType);
        Subject *ptrSubject = Subject::deserialize(in);

        if(ptrSubject != nullptr)
        {
            emit insertSubject(row, column, *(ptrSubject));
        }
    }
    else if(event->mimeData()->hasFormat(Inventory::mimeTypeForMove))
    {
        QByteArray in;
        in = event->mimeData()->data(Inventory::mimeTypeForMove);
        QDataStream dataStream(&in, QIODevice::ReadOnly);
        QPoint point;
        dataStream >> point;

        int row = this->indexAt(event->pos()).row();
        int column = this->indexAt(event->pos()).column();

        emit signalMoveSubject(point.x(), point.y(), row, column);
    }
}

void TableWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        _dragStartPosition = event->pos();
    }
    else if(event->button() & Qt::RightButton)
    {
        int row = this->indexAt(event->pos()).row();
        int column = this->indexAt(event->pos()).column();

        if(this->item(row, column) != nullptr)
        {
            emit removeSubject(row, column);
            emit signalPlayAppleBite();
        }
    }

    return QTableWidget::mousePressEvent(event);
}

void TableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) &&
            ((event->pos() - _dragStartPosition).manhattanLength() <
            QApplication::startDragDistance()))
    {
        int row = this->indexAt(event->pos()).row();
        int column = this->indexAt(event->pos()).column();

        if(this->item(row, column) != nullptr)
        {
            QDrag *drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;

            QPoint point(row, column);

            QByteArray byteArray;
            QDataStream dataStream(&byteArray, QIODevice::WriteOnly);
            dataStream << point;

            mimeData->setData(Inventory::mimeTypeForMove, byteArray);
            drag->setMimeData(mimeData);

            QString text = this->item(row, column)->text();
            QPixmap pixmap = this->item(row, column)->icon().pixmap(QSize(CELL_WIDTH, CELL_HEIGHT));
            QPainter painter(&pixmap);
            painter.drawText(0,
                             0,
                             CELL_WIDTH,
                             CELL_HEIGHT,
                             Qt::AlignBottom | Qt::AlignRight,
                             text);
            drag->setPixmap(pixmap);
            drag->setHotSpot(QPoint(CELL_WIDTH / 2, CELL_HEIGHT / 2));

            Qt::DropAction dropAction = drag->exec(Qt::MoveAction);
        }
    }

    return QTableWidget::mouseMoveEvent(event);
}
