#ifndef AZIMUTHLAYER_H
#define AZIMUTHLAYER_H

#include <cmath>

#include "Layer.h"
#include "Distributors/AzimuthConsumer.h"

class AzimuthLayer : public Layer
                   , public AzimuthConsumer
{
public:
    AzimuthLayer();
    void draw() override;
    void setAzimuth(std::shared_ptr<Azimuth> &azimuth) override;

private:
    QPen pen;
    double azimuth = -M_PI_2;
    uint8_t azimuth256 = 0;

    const int lineSize = 550;
};

#endif // AZIMUTHLAYER_H
