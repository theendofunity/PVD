#ifndef AZIMUTHCONSUMER_H
#define AZIMUTHCONSUMER_H

#include <memory>

#include "libs/Azimuth.h"

//Потребитель

class AzimuthConsumer
{
public:
    virtual ~AzimuthConsumer() = default;

    virtual void setAzimuth(std::shared_ptr<Azimuth> &message) = 0;
};

#endif // AZIMUTHCONSUMER_H
