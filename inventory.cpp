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

InventoryCell Inventory::inventoryCell(const int row, const int column)
{
    if(row >= _rows || column >= _columns)
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

    if(_mapInventoryCells[row][column].subject() == subject)
    {
        _mapInventoryCells[row][column].addSubject(subject, subjectCount);
        emit signalUpdateValueInInventoryCell(_mapInventoryCells[row][column].numberSubject(),
                                     row,
                                     column);
    }
    else
    {
        _mapInventoryCells[row][column].addSubject(subject, subjectCount);
        emit signalUpdateInventoryCell(row, column, _mapInventoryCells[row][column]);
    }
}

void Inventory::deleteSubjectInInventoryCell(const int row, const int column, const int subjectCount)
{
    if((row >= _rows || row < 0) ||
            (column >= _columns || column < 0))
        return;

    if(subjectCount <= 0)
    {
        return;
    }

    _mapInventoryCells[row][column].deleteSubject(subjectCount);

    if(_mapInventoryCells[row][column].isEmpty())
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

    InventoryCell inventoryCell = _mapInventoryCells[sourceRow][sourceColumn];

    if(inventoryCell.isEmpty())
    {
        return;
    }

    this->deleteSubjectInInventoryCell(sourceRow,
                                       sourceColumn,
                                       inventoryCell.numberSubject());

    this->addSubjectOfInventoryCell(receiverRow,
                                    receiverColumn,
                                    inventoryCell.subject(),
                                    inventoryCell.numberSubject());
}
