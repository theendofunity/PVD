#ifndef PVDSYSTEM_H
#define PVDSYSTEM_H

#include <memory>

#include "GridLayer.h"

class Canvas;
class LayersManager;

class PVDSystem
{
public:
    PVDSystem();

    Canvas *getCanvas() const;

private:
    void createLayers();

private:
    Canvas *canvas = nullptr;
    std::shared_ptr<LayersManager> manager = nullptr;

    std::unique_ptr<GridLayer> gridLayer = nullptr;

};

#endif // PVDSYSTEM_H
