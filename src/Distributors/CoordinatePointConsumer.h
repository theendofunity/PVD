#ifndef COORDINATEPOINTCONSUMER_H
#define COORDINATEPOINTCONSUMER_H

#include <memory>
#include "libs/AtcrbsCoordinatePoint.h"
#include "libs/CoordinatePoint.h"

class CoordinatePointConsumer
{
public:
    virtual ~CoordinatePointConsumer() = default;

    virtual void addCp(std::shared_ptr<pvd::CoordinatePoint> &message) = 0;
};

#endif // COORDINATEPOINTCONSUMER_H
