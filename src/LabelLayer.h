#ifndef LABELLAYER_H
#define LABELLAYER_H

#include <src/Layer.h>

#include <memory>

class PointContainer;

class LabelLayer : public Layer
{
public:
    LabelLayer(std::shared_ptr<PointContainer> container);

    void draw() override;

private:
    std::shared_ptr<PointContainer> container;
};

#endif // LABELLAYER_H
