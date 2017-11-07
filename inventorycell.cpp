#include "inventorycell.h"

const QString InventoryCell::mimeType = "data/inventorycell";

InventoryCell::InventoryCell() :
    _subject(),
    _numberSubject(0)
{}

InventoryCell::InventoryCell(const InventoryCell &inventoryCell) :
    _subject(inventoryCell._subject),
    _numberSubject(inventoryCell._numberSubject)
{}

InventoryCell &InventoryCell::operator=(const InventoryCell &inventoryCell)
{
    if(this != &inventoryCell)
    {
        _subject = inventoryCell._subject;
        _numberSubject = inventoryCell._numberSubject;
    }
    return *this;
}

Subject InventoryCell::subject() const
{
    return _subject;
}

int InventoryCell::numberSubject() const
{
    return _numberSubject;
}

bool InventoryCell::isEmpty() const
{
    return (_numberSubject == 0);
}

void InventoryCell::addSubject(const Subject &subject,
                               const int subjectCount)
{
    if(_subject == subject)
    {
        _numberSubject += subjectCount;
    }
    else
    {
        this->clear();
        _subject = subject;
        _numberSubject += subjectCount;
    }
}

void InventoryCell::deleteSubject(const int subjectCount)
{
    _numberSubject -= subjectCount;
    if(_numberSubject <= 0)
    {
        this->clear();
    }
}

void InventoryCell::clear()
{
    _subject.clear();
    _numberSubject = 0;
}

QDataStream & operator<<(QDataStream &out,
                         const InventoryCell &inventoryCell)
{
    out << inventoryCell._subject << inventoryCell._numberSubject;
    return out;
}

QDataStream & operator>>(QDataStream &in,
                         InventoryCell &invenoryCell)
{
    in >> invenoryCell._subject;
    in >> invenoryCell._numberSubject;
    return in;
}

InventoryCell::~InventoryCell()
{}
