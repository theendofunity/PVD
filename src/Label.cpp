#include "Label.h"

#include <cmath>

#include <libs/CoordinatePoint.h>

Label::Label(std::shared_ptr<pvd::CoordinatePoint> cp)
    :cp(cp)
{
    calcPosition();
    createTitle();
}

void Label::draw(QPainter &painter, double scale)
{
    painter.setPen(Qt::green);
    QFont font;
    font.setPointSize(8);
    painter.setFont(font);

    int i = 1;
    for (auto & string : title)
    {
        auto point = QPointF(x + 15, y + 10 * i) * scale;
        painter.drawText(point, string);
        i++;
    }
}

void Label::calcPosition()
{
    x = std::sin(cp->azimuth) * cp->range / 1000;
    y = -std::cos(cp->azimuth) * cp->range / 1000;
}

void Label::createTitle()
{
    title << QString::number(cp->bortNumber)
          << QString::number(cp->azimuth) + " rad"
          << QString::number(cp->range) + " m"
          << QString::number(cp->height) + " m";
}
