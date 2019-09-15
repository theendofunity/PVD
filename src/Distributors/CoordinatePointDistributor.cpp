#include "CoordinatePointDistributor.h"


CoordinatePointDistributor::CoordinatePointDistributor()
{

}

void CoordinatePointDistributor::addConsumer(CoordinatePointConsumer *consumer)
{
    consumers.push_back(consumer);
}

void CoordinatePointDistributor::notifyConsumers(std::shared_ptr<pdp::AtcrbsCoordinatePoint> &message)
{
    for(auto &consumer : consumers)
    {
        consumer->addCp(message);
    }
}
