#ifndef COORDINATEPOINT_H
#define COORDINATEPOINT_H

#include <QString>
#include <memory>

#include "IItem.h"
#include "Label.h"

namespace pvd
{
    class CoordinatePoint;
}

class CoordinatePoint : public IItem
{
public:
    CoordinatePoint(std::shared_ptr<pvd::CoordinatePoint> cp);
    ~CoordinatePoint() override;

    void draw(QPainter &painter, double scale) override;

    Label *getLabel() const;

private:
    uint8_t boardNumber;
    double azimuth = 0; //rad
    double altitude = 0;
    double range = 0;

    QPointF center;

    QColor color = Qt::blue;
    QSize size;

    Label* label = nullptr;
};

#endif // COORDINATEPOINT_H
