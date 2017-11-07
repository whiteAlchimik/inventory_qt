#include "inventorycell.h"

InventoryCell::InventoryCell() :
    _subject(),
    _numberSubject(0)
{}

InventoryCell::InventoryCell(const InventoryCell &inventoryCell) :
    _subject(inventoryCell._subject),
    _numberSubject(inventoryCell._numberSubject)
{}

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

InventoryCell::~InventoryCell()
{}
