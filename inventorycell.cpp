#include "inventorycell.h"

InventoryCell::InventoryCell() :
    _subject(),
    _numberSubject(0)
{}

Subject InventoryCell::subject() const
{
    return _subject;
}

void InventoryCell::setSubject(const Subject &subject)
{
    _subject = subject;
}

size_t InventoryCell::numberSubject() const
{
    return _numberSubject;
}

void InventoryCell::incrementNumberSubject()
{
    _numberSubject += 1;
}

void InventoryCell::decrementNumberSubject()
{
    if(_numberSubject == 0)
        return;

    _numberSubject -= 1;
}
