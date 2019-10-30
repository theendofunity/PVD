#ifndef COORDINATEPOINTCONSUMER_H
#define COORDINATEPOINTCONSUMER_H

#include <memory>
#include "libs/CpMessage.h"

class CoordinatePointConsumer
{
public:
    virtual ~CoordinatePointConsumer() = default;

    virtual void addCp(std::shared_ptr<CpMessage> &message) = 0;
};

#endif // COORDINATEPOINTCONSUMER_H
