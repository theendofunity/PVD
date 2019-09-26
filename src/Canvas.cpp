#include "Canvas.h"

#include <QPainter>
#include <QResizeEvent>

Canvas::Canvas(QWidget *parent)
    :QWidget(parent)
{
    setWindowTitle("PVD");
    setAttribute(Qt::WA_NoBackground);
    setStyleSheet("background-color:black;");
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter;

    QBrush brush;
    brush.setColor(Qt::black);

    painter->setBackground(brush);
    painter->drawPixmap(center, m_base);
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    m_base = QPixmap(event->size());
    m_base.fill(Qt::black);
}
