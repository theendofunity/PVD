#include "PointContainer.h"

#include "libs/Azimuth.h"
#include "CoordinatePoint.h"

#include <QDebug>

//-----------------------------------------------------------------------

static uint8_t currentSector(Azimuth &azimuth)
{
    return static_cast<uint8_t>(azimuth.toAzimuthCode() >> 8);
}
static uint8_t nextSector(Azimuth &azimuth)
{
    return static_cast<uint8_t>((azimuth.toAzimuthCode() >> 8) + 2);
}

//-----------------------------------------------------------------------
PointContainer::PointContainer()
{

}

void PointContainer::addCp(std::shared_ptr<pvd::CoordinatePoint> &message)
{
    auto cp = std::make_shared<CoordinatePoint>(message);

    auto pointAzimuth = Azimuth::fromRadians(message->azimuth);
    points[currentSector(pointAzimuth)].push_back(cp);
}

void PointContainer::setAzimuth(std::shared_ptr<Azimuth> &azimuth)
{
    auto nextAzimuth = nextSector(*azimuth.get());

    removeOldItems(nextAzimuth);
}

QList<std::shared_ptr<CoordinatePoint> > PointContainer::data()
{
    QList<std::shared_ptr<CoordinatePoint>> data;

    for (auto &sector : points.values())
    {
        for (auto &item : sector)
        {
            data.push_back(item);
        }
    }
    return data;
}

void PointContainer::removeOldItems(uint8_t sector)
{
    if (!points[sector].isEmpty())
        points[sector].clear();
}
