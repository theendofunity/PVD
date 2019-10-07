#include "Layer.h"
#include <QDebug>

void Layer::setScale(qreal scale)
{
    this->scale += scale;

    if (this->scale < 0)    //Ограничение уменьшения
    {
        this->scale = 0;
    }

    draw();
}

void Layer::setSize(QSize size)
{
    this->size = size;
    auto newSizePixmap = QPixmap(size);
    m_current = newSizePixmap;
    m_current.fill(Qt::transparent);
    m_cashed = newSizePixmap;
    m_cashed.fill(Qt::transparent);
}

void Layer::setOrigin(QPointF origin)
{
    this->origin += origin;

    draw();
}

QPixmap &Layer::pixmap()
{
    return m_cashed;
}

void Layer::initPainter(QPainter &painter)
{
    QRect r(QPoint(), size);
    r.moveCenter(QPoint());
    painter.setWindow(r);
    painter.translate(origin);
    painter.scale(scale, scale);
}
