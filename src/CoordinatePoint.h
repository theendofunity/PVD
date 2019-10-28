#ifndef COORDINATEPOINT_H
#define COORDINATEPOINT_H

#include <QString>
#include <memory>

#include "IItem.h"
#include "Label.h"

class CpMessage;

class CoordinatePoint : public IItem
{
public:
    CoordinatePoint(std::shared_ptr<CpMessage> cp);
    ~CoordinatePoint() override;

    void draw(QPainter &painter, double scale) override;

    Label *getLabel() const;

private:

    QPointF center;

    QColor color = Qt::blue;
    QSize size;

    Label* label = nullptr;
};

#endif // COORDINATEPOINT_H
