#include "CoordinatePoint.h"
#include <libs/CpMessage.h>

#include <math.h>

CoordinatePoint::CoordinatePoint(std::shared_ptr<CpMessage> cp)
{
    size = QSize(10, 10);
    center = QPointF(std::sin(cp->azimuth), -std::cos(cp->azimuth)) * cp->range / 1000;

    label = new Label(cp);
}

CoordinatePoint::~CoordinatePoint()
{
    delete label;
}

void CoordinatePoint::draw(QPainter &painter, double scale)
{
    painter.setBrush(color);

    QRectF rec(QPointF(), size);
    rec.moveCenter(center * scale);
    painter.drawEllipse(rec);
}

Label *CoordinatePoint::getLabel() const
{
    return label;
}
