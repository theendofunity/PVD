#include "LabelLayer.h"

#include "PointContainer.h"

#include "CoordinatePoint.h"

LabelLayer::LabelLayer(std::shared_ptr<PointContainer> container)
    : container(container)
{

}

void LabelLayer::draw()
{
    m_current.fill(Qt::transparent);
    if (m_current.isNull())
        return;

    QPainter painter(&m_current);
    initPainter(painter);
    for (auto &item : container->data())
    {
        item->getLabel()->draw(painter, scale);
    }

    m_cashed = std::move(m_current);
}
