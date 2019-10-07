#ifndef COORDINATEPOINTCONSUMER_H
#define COORDINATEPOINTCONSUMER_H

#include <memory>
#include "libs/AtcrbsCoordinatePoint.h"

class CoordinatePointConsumer
{
public:
    virtual ~CoordinatePointConsumer() = default;

    virtual void addCp(std::shared_ptr<pdp::AtcrbsCoordinatePoint> &message) = 0;
};

#endif // COORDINATEPOINTCONSUMER_H
