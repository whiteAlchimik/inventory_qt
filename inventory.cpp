#include "inventory.h"

const QString Inventory::mimeTypeForMove = "data/sourceCell";

Inventory::Inventory(const int rows,
                     const int columns,
                     QObject *parent) :
    _rows(rows),
    _columns(columns),
    _mapInventoryCells(_rows, QVector<InventoryCell>(_columns)),
    QObject(parent)
{}

size_t Inventory::rows() const
{
    return _rows;
}

size_t Inventory::columns() const
{
    return _columns;
}

InventoryCell Inventory::inventoryCell(const int row, const int column) const
{
    if((row >= _rows || row < 0) ||
            (column >= _columns || column < 0))
        return InventoryCell();

    return _mapInventoryCells[row][column];
}

Inventory::~Inventory()
{}

void Inventory::addSubjectOfInventoryCell(const int row,
                                          const int column,
                                          const Subject &subject,
                                          const int subjectCount)
{
    if((row >= _rows || row < 0) ||
            (column >= _columns || column < 0) ||
            subjectCount <= 0)
    {
        return;
    }

    InventoryCell::STATE state = _mapInventoryCells[row][column].addSubject(subject,
                                                                            subjectCount);
    if(state == InventoryCell::WEAK_STATE)
    {
        emit signalUpdateInventoryCell(row, column, _mapInventoryCells[row][column]);
    }
    else if(state == InventoryCell::STRONG_STATE)
    {
        emit signalUpdateValueInInventoryCell(_mapInventoryCells[row][column].numberSubject(),
                                     row,
                                     column);
    }
}

void Inventory::deleteSubjectInInventoryCell(const int row,
                                             const int column,
                                             const int subjectCount)
{
    if((row >= _rows || row < 0) ||
            (column >= _columns || column < 0) ||
            subjectCount <= 0)
    {
        return;
    }

    InventoryCell::STATE state = _mapInventoryCells[row][column].deleteSubject(subjectCount);
    if(state == InventoryCell::EMPTY)
    {
        emit inventoryCellIsEmpty(row, column);
        return;
    }

    emit signalUpdateValueInInventoryCell(_mapInventoryCells[row][column].numberSubject(),
                                 row,
                                 column);
}

void Inventory::moveSubjectInInventory(const int sourceRow,
                                       const int sourceColumn,
                                       const int receiverRow,
                                       const int receiverColumn)
{
    if((sourceRow < 0 || sourceRow >= _rows) ||
            (sourceColumn < 0 || sourceColumn >= _columns) ||
            (receiverRow < 0 || receiverRow >= _rows) ||
            (receiverColumn < 0 || receiverColumn >= _columns))
    {
        return;
    }

    if(_mapInventoryCells[sourceRow][sourceColumn].isEmpty())
    {
        return;
    }

    this->addSubjectOfInventoryCell(receiverRow,
                                    receiverColumn,
                                    *(_mapInventoryCells[sourceRow][sourceColumn].subject()),
                                    _mapInventoryCells[sourceRow][sourceColumn].numberSubject());

    this->deleteSubjectInInventoryCell(sourceRow,
                                       sourceColumn,
                                       _mapInventoryCells[sourceRow][sourceColumn].numberSubject());
}

QVariantList Inventory::prepareDataForDataBase(const int row, const int column)
{
    if((row >= _rows || row < 0) ||
            (column >= _columns || column < 0))
    {
        return QVariantList();
    }

    QVariantList data;

    data.append(_rows);
    data.append(_columns);
    data.append(row);
    data.append(column);
    data.append(_mapInventoryCells[row][column].numberSubject());
    data.append(_mapInventoryCells[row][column].subject()->serializationId());

    return data;
}
