#include "CoordinatePointDistributor.h"

#include <QDebug>

CoordinatePointDistributor::CoordinatePointDistributor()
{

}

void CoordinatePointDistributor::addConsumer(CoordinatePointConsumer *consumer)
{
    consumers.push_back(consumer);
}

void CoordinatePointDistributor::notifyConsumers(std::shared_ptr<CpMessage> message)
{
    for(auto &consumer : consumers)
    {
        consumer->addCp(message);
    }
}
