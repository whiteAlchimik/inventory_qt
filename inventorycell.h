#ifndef INVENTORYCELL_H
#define INVENTORYCELL_H

#include <QDataStream>
#include <QString>

#include "subject.h"

class InventoryCell
{
public:

    static const QString mimeType;

    enum STATE : qint8 {EMPTY = 0, //inventory cell is empty
                        WEAK_STATE, //inventory cell has one subject
                        STRONG_STATE}; //inventory cell has >1 subject

    InventoryCell();

    InventoryCell(const InventoryCell &inventoryCell);

    InventoryCell & operator=(const InventoryCell &inventoryCell);

    const Subject * subject() const;

    int numberSubject() const;

    /*
     * Checks if the inventory cell has no subject.
     * Return value : true if the inventory cell is empty,
     *                false otherwise
     */
    bool isEmpty() const;

    STATE addSubject(const Subject &subject,
                    const int subjectCount = 1);

    STATE deleteSubject(const int subjectCount = 1);

    void clear();

    /*friend QDataStream & operator<<(QDataStream &out,
                                    const InventoryCell &inventoryCell);

    friend QDataStream & operator>>(QDataStream &in,
                                    InventoryCell &inventoryCell);*/

    ~InventoryCell();

private:
    STATE _state;
    Subject *_ptrSubject;
    int _numberSubject;
};

#endif // INVENTORYCELL_H
