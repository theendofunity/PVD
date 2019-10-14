#ifndef PVDSYSTEM_H
#define PVDSYSTEM_H

#include <memory>

#include "GridLayer.h"
#include "AzimuthLayer.h"
#include "PointLayer.h"
#include "LabelLayer.h"

class Canvas;
class LayersManager;

class AzimuthDistributor;
class CoordinatePointDistributor;

class PVDSystem
{
public:
    PVDSystem();

    Canvas *getCanvas() const;
    void associateWith(AzimuthDistributor* distr);
    void associateWith(CoordinatePointDistributor* distr);

private:
    void createLayers();

private:
    Canvas *canvas = nullptr;
    std::shared_ptr<LayersManager> manager = nullptr;

    std::shared_ptr<PointContainer> points = nullptr;

    std::unique_ptr<GridLayer> gridLayer = nullptr;
    std::unique_ptr<AzimuthLayer> azimuthLayer = nullptr;
    std::unique_ptr<PointLayer> pointLayer = nullptr;
    std::unique_ptr<LabelLayer> labelLayer = nullptr;

};

#endif // PVDSYSTEM_H
