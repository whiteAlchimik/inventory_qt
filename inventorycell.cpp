#include "inventorycell.h"

const QString InventoryCell::mimeType = "data/inventorycell";

InventoryCell::InventoryCell() :
    _state(STATE::EMPTY),
    _ptrSubject(nullptr),
    _numberSubject(0)
{}

InventoryCell::InventoryCell(const InventoryCell &inventoryCell) :
    _state(inventoryCell._state),
    _ptrSubject(nullptr),
    _numberSubject(inventoryCell._numberSubject)
{
    if(inventoryCell._ptrSubject != nullptr)
        _ptrSubject = inventoryCell._ptrSubject->clone();
}

InventoryCell &InventoryCell::operator=(const InventoryCell &inventoryCell)
{
    if(this != &inventoryCell)
    {
        _state = inventoryCell._state;
        _ptrSubject = nullptr;
        if(inventoryCell._ptrSubject != nullptr)
            _ptrSubject = inventoryCell._ptrSubject->clone();
        _numberSubject = inventoryCell._numberSubject;
    }
    return *this;
}

const Subject * InventoryCell::subject() const
{
    return _ptrSubject;
}

int InventoryCell::numberSubject() const
{
    return _numberSubject;
}

bool InventoryCell::isEmpty() const
{
    return (_numberSubject == 0);
}

InventoryCell::STATE InventoryCell::addSubject(const Subject &subject,
                               const int subjectCount)
{
    if(subject.cmp(_ptrSubject))
    {
        _numberSubject += subjectCount;
        _state = STATE::STRONG_STATE;
    }
    else
    {
        this->clear();
        _ptrSubject = subject.clone();
        _numberSubject += subjectCount;
        _state = STATE::WEAK_STATE;
    }

    return _state;
}

InventoryCell::STATE InventoryCell::deleteSubject(const int subjectCount)
{
    _numberSubject -= subjectCount;
    if(_numberSubject <= 0)
    {
        this->clear();
        _state = STATE::EMPTY;
    }

    return _state;
}

void InventoryCell::clear()
{
    _state = STATE::EMPTY;
    delete _ptrSubject;
    _ptrSubject = nullptr;
    _numberSubject = 0;
}
/*
QDataStream & operator<<(QDataStream &out,
                         const InventoryCell &inventoryCell)
{
    //out << inventoryCell._subject << inventoryCell._numberSubject;
    return out;
}

QDataStream & operator>>(QDataStream &in,
                         InventoryCell &invenoryCell)
{
    //in >> invenoryCell._subject;
    //in >> invenoryCell._numberSubject;
    return in;
}
*/
InventoryCell::~InventoryCell()
{
    this->clear();
}

