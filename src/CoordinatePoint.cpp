#include "CoordinatePoint.h"
#include <libs/AtcrbsCoordinatePoint.h>

CoordinatePoint::CoordinatePoint(std::shared_ptr<pdp::AtcrbsCoordinatePoint> cp)
{
    azimuth = cp->azimuth;
    range = cp->range;
    altitude = cp->altitude;
    boardNumber = static_cast<uint8_t>(cp->bortNumber);
}

void CoordinatePoint::draw(QPainter *painter)
{

}
