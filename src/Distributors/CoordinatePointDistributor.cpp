#include "CoordinatePointDistributor.h"

#include <QDebug>

CoordinatePointDistributor::CoordinatePointDistributor()
{

}

void CoordinatePointDistributor::addConsumer(CoordinatePointConsumer *consumer)
{
    consumers.push_back(consumer);
    qDebug() << consumers.size();
}

void CoordinatePointDistributor::notifyConsumers(std::shared_ptr<pvd::CoordinatePoint> message)
{
    for(auto &consumer : consumers)
    {
        consumer->addCp(message);
    }
}
