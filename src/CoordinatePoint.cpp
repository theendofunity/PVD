#include "CoordinatePoint.h"
#include <libs/CoordinatePoint.h>

#include <QDebug>

CoordinatePoint::CoordinatePoint(std::shared_ptr<pvd::CoordinatePoint> cp)
{
    azimuth = cp->azimuth;
    range = cp->range;
    altitude = cp->height;
    boardNumber = static_cast<uint8_t>(cp->bortNumber);

    size = QSize(10, 10);
    center = QPointF(std::sin(azimuth), -std::cos(azimuth)) * range / 1000;
}

void CoordinatePoint::draw(QPainter &painter, double scale)
{
    painter.setPen(color);

    QRectF rec(QPointF(), size);
    rec.moveCenter(center * scale);
    painter.drawEllipse(rec);
}
