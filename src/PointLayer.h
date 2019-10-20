#ifndef POINTLAYER_H
#define POINTLAYER_H

#include "memory"

#include <src/Layer.h>

class PointContainer;

class PointLayer : public Layer
{
public:
    PointLayer(std::shared_ptr<PointContainer> container);

    void draw() override;

private:
    std::shared_ptr<PointContainer> container;
};

#endif // POINTLAYER_H
