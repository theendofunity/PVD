#ifndef LAYERSMANAGER_H
#define LAYERSMANAGER_H

#include "ILayer.h"

#include <QList>

class LayersManager : public ILayer
{
public:
    LayersManager();

    void addLayer(ILayer* layer);

    void draw() override;
    void drawPixmap(QPainter &painter, QPoint center);
    void setSize(QSize size) override;
    void setScale(qreal scale) override;
    void setOrigin(QPointF origin) override;

    QPixmap & pixmap() override {}

private:
    QList<ILayer*> layers;
};

#endif // LAYERSMANAGER_H
