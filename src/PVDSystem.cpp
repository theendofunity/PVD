#include "PVDSystem.h"

#include "Canvas.h"
#include "LayersManager.h"
#include "Distributors/AzimuthDistributor.h"

#include <src/GridLayer.h>

PVDSystem::PVDSystem()
{
    Azimuth::setAzimuthCodeLSB( (M_PI * 2) / (1 << 16) );

    manager = std::make_shared<LayersManager>();

    canvas = new Canvas(manager);

    createLayers();
}

Canvas *PVDSystem::getCanvas() const
{
    return canvas;
}

void PVDSystem::associateWith(AzimuthDistributor *distr)
{
    distr->addConsumer(azimuthLayer.get());
}

void PVDSystem::createLayers()
{
    gridLayer = std::make_unique<GridLayer>();
    manager->addLayer(gridLayer.get());

    azimuthLayer = std::make_unique<AzimuthLayer>();
    manager->addLayer(azimuthLayer.get());
}
