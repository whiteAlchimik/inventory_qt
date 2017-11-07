#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QVector>
#include "inventorycell.h"

class Inventory : public QObject
{

    Q_OBJECT

public:
    Inventory(const int rows,
              const int columns,
              QObject *parent = nullptr);

    size_t rows() const;

    size_t columns() const;

    InventoryCell inventoryCell(const int row, const int column);

    ~Inventory();

signals:
    void createWidgetSubject(const int row, const int column);
    void destroyWidgetSubject(const int row, const int column);
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

private:
    int _rows;
    int _columns;
    QVector<QVector<InventoryCell>> _mapInventoryCells;
};

#endif // INVENTORY_H
