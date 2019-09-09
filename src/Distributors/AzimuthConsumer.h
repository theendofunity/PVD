#ifndef AZIMUTHCONSUMER_H
#define AZIMUTHCONSUMER_H

#include <memory>

#include "libs/PeriodRepetitionAzimuth.h"

//Потребитель

class AzimuthConsumer
{
public:
    virtual ~AzimuthConsumer();

    virtual void handle(std::shared_ptr<dsp::PeriodRepetitionAzimuth> &message) = 0;
};

#endif // AZIMUTHCONSUMER_H
