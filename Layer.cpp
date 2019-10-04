#include "Layer.h"

void Layer::setScale()
{

}

void Layer::setSize(QSize size)
{
    this->size = size;
    auto newSizePixmap = QPixmap(size);
    m_current = newSizePixmap;
    m_current.fill(Qt::transparent);
    m_cashed = newSizePixmap;
    m_cashed.fill(Qt::transparent);
//    widgetToSceneTranslator = makeTranslator();
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
    painter.translate(origin * scale);
}
