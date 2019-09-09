#ifndef COORDINATEPOINTCONSUMER_H
#define COORDINATEPOINTCONSUMER_H

#include <memory>
#include "libs/AtcrbsCoordinatePoint.h"

class CoordinatePointConsumer
{
public:
//    virtual ~CoordinatePointConsumer();

    virtual void handle(std::shared_ptr<pdp::AtcrbsCoordinatePoint> &message) = 0;
};

#endif // COORDINATEPOINTCONSUMER_H
