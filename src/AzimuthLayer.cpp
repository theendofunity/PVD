#include "AzimuthLayer.h"

#include <QDebug>

AzimuthLayer::AzimuthLayer()
{
    pen.setWidth(3);
    pen.setColor(Qt::red);
}

void AzimuthLayer::draw()
{
    m_current.fill(Qt::transparent);
    if (m_current.isNull())
        return;

    QPainter painter(&m_current);
    initPainter(painter);

//    painter.translate(-origin * scale);
    painter.setPen(pen);

    QPointF point2(lineSize * std::cos(azimuth),
                   lineSize * std::sin(azimuth));
    point2 *= scale;
    painter.drawLine({0, 0}, point2);

    m_cashed = std::move(m_current);
}

void AzimuthLayer::setAzimuth(std::shared_ptr<Azimuth> &azimuth)
{
    auto sensorAzimuth = azimuth->toAzimuthCode();
    sensorAzimuth >>= 8;

    if (sensorAzimuth != azimuth256)
    {
        azimuth256 = static_cast<uint8_t>(sensorAzimuth);
        this->azimuth = azimuth->toRadians() - M_PI_2;
    }
}
