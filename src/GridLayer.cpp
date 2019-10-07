#include "GridLayer.h"

#include <cmath>

GridLayer::GridLayer()
{

}

void GridLayer::draw()
 {
    if (m_current.isNull())
        return;

    m_current.fill(Qt::transparent);

    drawGrid();
}

void GridLayer::drawGrid()
{
    QPainter painter(&m_current);
    initPainter(painter);

    QPen pen(Qt::gray, 0, Qt::SolidLine);
    painter.setPen(pen);

    //Рисуем радиусы
    auto sectorSingleStep = static_cast<double>(SingleStep_Sector * M_PI / 180.0);
    for (auto alpha = 0.0; alpha < 2 * M_PI; alpha += sectorSingleStep)
    {
        int x1 = static_cast<int>(std::round(minRange * std::cos(alpha) * scale));
        int y1 = static_cast<int>(std::round(minRange * std::sin(alpha) * scale));
        int x2 = static_cast<int>(std::round(maxRange * std::cos(alpha) * scale));
        int y2 = static_cast<int>(std::round(maxRange * std::sin(alpha) * scale));

        painter.drawLine(x1, y1, x2, y2);
    }

    //Рисуем окружности
    for (int i = SingleStep_Range; i <= maxRange; i += SingleStep_Range)
    {
        pen.setStyle( (i % (2 * SingleStep_Range) == 0) ? Qt::SolidLine : Qt::DotLine);
        painter.setPen(pen);

        int diametr = static_cast<int>(std::round(i * scale)) << 1;
        QRect circleRect(QPoint(), QSize(diametr, diametr));
        circleRect.moveCenter( QPoint(0, 0) );

        painter.drawEllipse(circleRect);
    }

    m_cashed = std::move(m_current);
}
