#ifndef AZIMUTHDISTRIBUTOR_H
#define AZIMUTHDISTRIBUTOR_H

#include <QList>
#include <memory>

#include "AzimuthConsumer.h"
#include "libs/Azimuth.h"


//Паттерн наблюдатель

class AzimuthDistributor
{
public:
    AzimuthDistributor();

    //Добавление потребителя
    void addConsumer(AzimuthConsumer *consumer);
    //Уведомление потребителя
    void notifyConsumers(std::shared_ptr<Azimuth> message);

private:
    QList <AzimuthConsumer*> consumers;
};

#endif // AZIMUTHDISTRIBUTOR_H
