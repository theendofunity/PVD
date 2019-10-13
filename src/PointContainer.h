#ifndef POINTCONTAINER_H
#define POINTCONTAINER_H

#include <QMap>
#include <QList>

#include "Distributors/CoordinatePointConsumer.h"
#include "Distributors/AzimuthConsumer.h"

class CoordinatePoint;

class PointContainer : public CoordinatePointConsumer
                     , public AzimuthConsumer
{
public:
    PointContainer();
    void addCp(std::shared_ptr<pvd::CoordinatePoint> &message) override;
    void setAzimuth(std::shared_ptr<Azimuth> &azimuth) override;
    QList<std::shared_ptr<CoordinatePoint>> data();
private:
    void removeOldItems(uint8_t sector);
private:

    using pointsInSector = QList<std::shared_ptr<CoordinatePoint>>;
    QMap<uint8_t, pointsInSector> points;

};

#endif // POINTCONTAINER_H
