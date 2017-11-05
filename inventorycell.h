#ifndef INVENTORYCELL_H
#define INVENTORYCELL_H

#include "subject.h"

class InventoryCell
{
public:
    InventoryCell();

    Subject subject() const;
    void setSubject(const Subject &subject);

    size_t numberSubject() const;

    void incrementNumberSubject();
    void decrementNumberSubject();

private:
    Subject _subject;
    size_t _numberSubject;
};

#endif // INVENTORYCELL_H
