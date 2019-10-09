#ifndef PVDSYSTEM_H
#define PVDSYSTEM_H

#include <memory>

#include "GridLayer.h"
#include "AzimuthLayer.h"

class Canvas;
class LayersManager;

class AzimuthDistributor;

class PVDSystem
{
public:
    PVDSystem();

    Canvas *getCanvas() const;
    void associateWith(AzimuthDistributor* distr);

private:
    void createLayers();

private:
    Canvas *canvas = nullptr;
    std::shared_ptr<LayersManager> manager = nullptr;

    std::unique_ptr<GridLayer> gridLayer = nullptr;
    std::unique_ptr<AzimuthLayer> azimuthLayer = nullptr;

};

#endif // PVDSYSTEM_H
