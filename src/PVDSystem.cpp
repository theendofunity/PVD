#include "PVDSystem.h"

#include "Canvas.h"

PVDSystem::PVDSystem()
{
    canvas = new Canvas();
}

Canvas *PVDSystem::getCanvas() const
{
    return canvas;
}
