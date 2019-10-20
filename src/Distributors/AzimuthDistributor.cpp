#include "AzimuthDistributor.h"

AzimuthDistributor::AzimuthDistributor()
{

}

void AzimuthDistributor::addConsumer(AzimuthConsumer *consumer)
{
    consumers.push_back(consumer);
}

void AzimuthDistributor::notifyConsumers(std::shared_ptr<Azimuth> message)
{
    for (auto &consumer : consumers)
    {
        consumer->setAzimuth(message);
    }
}
