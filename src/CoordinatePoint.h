#ifndef COORDINATEPOINT_H
#define COORDINATEPOINT_H

#include <QString>
#include <memory>

#include "IItem.h"

namespace pdp
{
    class AtcrbsCoordinatePoint;
}

class CoordinatePoint : public IItem
{
public:
    CoordinatePoint(std::shared_ptr<pdp::AtcrbsCoordinatePoint> cp);

    void draw(QPainter *painter) override;

private:
    uint8_t boardNumber;
    double azimuth = 0; //rad
    double altitude = 0;
    double range = 0;
};

#endif // COORDINATEPOINT_H
