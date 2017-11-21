#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QVector>
#include <QVariantList>

#include "inventorycell.h"
#include "subject.h"
#include "database.h"

class Inventory : public QObject
{

    Q_OBJECT

public:
    static const QString mimeTypeForMove;

    Inventory(const int rows,
              const int columns,
              QObject *parent = nullptr);

    size_t rows() const;

    size_t columns() const;

    //InventoryCell inventoryCell(const int row, const int column);

    ~Inventory();

signals:
    void signalUpdateInventoryCell(const int row,
                                   const int column,
                                   const InventoryCell &inventoryCell);
    void inventoryCellIsEmpty(const int row, const int column);
    void signalUpdateValueInInventoryCell(const int newValue,
                                 const int row,
                                 const int column);

public slots:
    void addSubjectOfInventoryCell(const int row,
                                   const int column,
                                   const Subject &subject,
                                   const int subjectCount = 1);

    void deleteSubjectInInventoryCell(const int row,
                                      const int column,
                                      const int subjectCount = 1);

    void moveSubjectInInventory(const int sourceRow,
                                const int sourceColumn,
                                const int receiverRow,
                                const int receiverColumn);

private:
    int _rows;
    int _columns;
    QVector<QVector<InventoryCell>> _mapInventoryCells;

    QVariantList prepareDataForDataBase(const int row, const int column);
};

#endif // INVENTORY_H
