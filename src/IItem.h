#ifndef IITEM_H
#define IITEM_H

#include "QPainter"

class IItem
{
public:
    virtual ~IItem() = default;
    virtual void draw(QPainter &painter) = 0;
};

#endif // IITEM_H
