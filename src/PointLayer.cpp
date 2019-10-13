#include "PointLayer.h"

#include "PointContainer.h"
#include "CoordinatePoint.h"

PointLayer::PointLayer(std::shared_ptr<PointContainer> container)
    : container(container)
{

}

void PointLayer::draw()
{
    m_current.fill(Qt::transparent);
    if (m_current.isNull())
        return;

    QPainter painter(&m_current);
    initPainter(painter);

    for (auto &item : container->data())
    {
        item->draw(painter);
    }

    m_cashed = std::move(m_current);
}
