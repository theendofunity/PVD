#ifndef LAYER_H
#define LAYER_H

#include "src/ILayer.h"

#include <QPixmap>
#include <QPainter>

class Layer : public ILayer
{
public:
    virtual void draw() override = 0 ;

    virtual void setScale(qreal scale) override;
    virtual void setSize(QSize size) override;
    virtual void setOrigin(QPointF origin) override;

    QPixmap& pixmap() override;

protected:
    void initPainter(QPainter &painter);

protected:
    QPixmap m_current; //Текущее, используется во время отрисовки
    QPixmap m_cashed; //После окончания отрисовки перемещается сюда,
    // и рисуется при вызове paintEvent

    QPointF origin = QPointF(); //Центр
    QSize size;
    qreal scale = 1.0;
};

#endif // LAYER_H
