#include "LayersManager.h"

#include <QPainter>

LayersManager::LayersManager()
{

}

void LayersManager::addLayer(ILayer *layer)
{
    layers.push_back(layer);
}

void LayersManager::draw()
{
    for (auto &layer : layers)
    {
        layer->draw();
    }
}

void LayersManager::drawPixmap(QPainter &painter, QPoint center)
{
    for (auto &layer : layers)
    {
        painter.drawPixmap(center, layer->pixmap());
    }
}

void LayersManager::setSize(QSize size)
{
    for (auto &layer : layers)
    {
        layer->setSize(size);
    }
}

void LayersManager::setScale()
{

}
