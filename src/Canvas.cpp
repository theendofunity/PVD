#include "Canvas.h"

#include <QPainter>
#include <QResizeEvent>
#include <QTimer>

#include <src/LayersManager.h>

Canvas::Canvas(std::shared_ptr<LayersManager> manager, QWidget *parent)
    :QWidget(parent)
    , manager(manager)
{
    setWindowTitle("PVD");
    setAttribute(Qt::WA_NoBackground);
    setStyleSheet("background-color:black;");

    QTimer *timer = new QTimer;

    //Обновление отображения
    QObject::connect(timer, &QTimer::timeout, this, &Canvas::updateView);
    timer->start(1000);
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBackground(QBrush(Qt::black));
    painter.drawPixmap(center, m_base);

    manager->drawPixmap(painter, center);
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    manager->setSize(event->size());

    m_base = QPixmap(event->size());
    m_base.fill(Qt::black);

    updateView();
}

void Canvas::updateView()
{
    manager->draw();
}
