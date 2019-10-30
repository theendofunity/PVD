#ifndef COORDINATEPOINTDISTRIBUTOR_H
#define COORDINATEPOINTDISTRIBUTOR_H

#include <memory>
#include <QList>

#include "CoordinatePointConsumer.h"

class CoordinatePointDistributor
{
public:
    CoordinatePointDistributor();

    void addConsumer(CoordinatePointConsumer* consumer);
    void notifyConsumers(std::shared_ptr<CpMessage> message);

private:
    QList<CoordinatePointConsumer*> consumers;
};

#endif // COORDINATEPOINTDISTRIBUTOR_H
