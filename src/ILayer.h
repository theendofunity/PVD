#ifndef ILAYER_H
#define ILAYER_H

//Интерфейсный класс для слоев и менеджера

#include <QPixmap>
#include <QSize>

class ILayer
{
public:
    virtual ~ILayer() = default;
    virtual void draw() = 0;

    virtual void setScale(qreal scale) = 0;
    virtual void setSize(QSize size) = 0;
    virtual void setOrigin(QPointF origin) = 0;
    virtual QPixmap& pixmap() = 0;
};

#endif // ILAYER_H
