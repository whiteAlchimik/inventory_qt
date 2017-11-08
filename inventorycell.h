#ifndef INVENTORYCELL_H
#define INVENTORYCELL_H

#include <QDataStream>
#include <QString>

#include "subject.h"

class InventoryCell
{
public:

    static const QString mimeType;

    InventoryCell();

    InventoryCell(const InventoryCell &inventoryCell);

    InventoryCell & operator=(const InventoryCell &inventoryCell);

    Subject subject() const;

    int numberSubject() const;

    /*
     * Checks if the inventory cell has no subject.
     * Return value : true if the inventory cell is empty,
     *                false otherwise
     */
    bool isEmpty() const;

    void addSubject(const Subject &subject,
                    const int subjectCount);

    void deleteSubject(const int subjectCount);

    void clear();

    friend QDataStream & operator<<(QDataStream &out,
                                    const InventoryCell &inventoryCell);

    friend QDataStream & operator>>(QDataStream &in,
                                    InventoryCell &inventoryCell);

    ~InventoryCell();

private:
    Subject _subject;
    int _numberSubject;
};

#endif // INVENTORYCELL_H
