#ifndef COORDINATEPOINTDISTRIBUTOR_H
#define COORDINATEPOINTDISTRIBUTOR_H

#include <memory>
#include <QList>

#include <libs/AtcrbsCoordinatePoint.h>

#include "CoordinatePointConsumer.h"

class CoordinatePointDistributor
{
public:
    CoordinatePointDistributor();

    void addConsumer(CoordinatePointConsumer* consumer);
    void notifyConsumers(std::shared_ptr<pdp::AtcrbsCoordinatePoint> message);

private:
    QList<CoordinatePointConsumer*> consumers;
};

#endif // COORDINATEPOINTDISTRIBUTOR_H
