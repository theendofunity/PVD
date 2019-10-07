#ifndef GRIDLAYER_H
#define GRIDLAYER_H

#include "Layer.h"

class GridLayer : public Layer
{
public:
    GridLayer();

    void draw() override;

    void drawGrid();

private:
    enum { SingleStep_Sector = 30, SingleStep_Range = 50 };
    int minRange = 6;
    int maxRange = 550;
};

#endif // GRIDLAYER_H
