#ifndef AZIMUTHDISTRIBUTOR_H
#define AZIMUTHDISTRIBUTOR_H

#include <QList>
#include <memory>

#include "AzimuthConsumer.h"
#include "libs/PeriodRepetitionAzimuth.h"


//Паттерн наблюдатель

class AzimuthDistributor
{
public:
    AzimuthDistributor();

    //Добавление потребителя
    void addConsumer(AzimuthConsumer *consumer);
    //Уведомление потребителя
    void notifyConsumers(std::shared_ptr<dsp::PeriodRepetitionAzimuth> &message);

private:
    QList <AzimuthConsumer*> consumers;
};

#endif // AZIMUTHDISTRIBUTOR_H
