#ifndef LAYER_H
#define LAYER_H

#include "src/ILayer.h"

#include <QPixmap>
#include <QPainter>

class Layer : public ILayer
{
public:
    virtual void draw() override = 0 ;

    virtual void setScale() override;
    virtual void setSize(QSize size) override;

    QPixmap& pixmap() override;

protected:
    void initPainter(QPainter &painter);

protected:
    QPixmap m_current;
    QPixmap m_cashed;

    QPointF origin = QPointF();
    QSize size = QSize(1000,1000);
    double scale = 1.0;

};

#endif // LAYER_H