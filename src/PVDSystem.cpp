#include "PVDSystem.h"

#include "Canvas.h"
#include "LayersManager.h"

#include <src/GridLayer.h>

PVDSystem::PVDSystem()
{
    manager = std::make_shared<LayersManager>();

    canvas = new Canvas(manager);

    createLayers();
}

Canvas *PVDSystem::getCanvas() const
{
    return canvas;
}

void PVDSystem::createLayers()
{
    gridLayer = std::make_unique<GridLayer>();
    manager->addLayer(gridLayer.get());
}
