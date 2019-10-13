#include "PVDSystem.h"

#include "Canvas.h"
#include "LayersManager.h"

#include "Distributors/AzimuthDistributor.h"
#include "Distributors/CoordinatePointDistributor.h"

#include "PointContainer.h"
#include <src/GridLayer.h>

PVDSystem::PVDSystem()
{
    Azimuth::setAzimuthCodeLSB( (M_PI * 2) / (1 << 16) );

    manager = std::make_shared<LayersManager>();

    canvas = new Canvas(manager);

    points = std::make_shared<PointContainer>();

    createLayers();
}

Canvas *PVDSystem::getCanvas() const
{
    return canvas;
}

void PVDSystem::associateWith(AzimuthDistributor *distr)
{
    distr->addConsumer(azimuthLayer.get());
    static_cast<AzimuthDistributor*>(distr)->addConsumer(points.get());
    static_cast<AzimuthDistributor*>(distr)->addConsumer(points.get());
}

void PVDSystem::associateWith(CoordinatePointDistributor *distr)
{
    static_cast<CoordinatePointDistributor*>(distr)->addConsumer(points.get());
}

void PVDSystem::createLayers()
{
    gridLayer = std::make_unique<GridLayer>();
    manager->addLayer(gridLayer.get());

    azimuthLayer = std::make_unique<AzimuthLayer>();
    manager->addLayer(azimuthLayer.get());

    pointLayer = std::make_unique<PointLayer>(points);
    manager->addLayer(pointLayer.get());
}
