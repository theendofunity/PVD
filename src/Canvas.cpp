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
    setFocusPolicy(Qt::StrongFocus);

    QTimer *timer = new QTimer;

    //Обновление отображения
    QObject::connect(timer, &QTimer::timeout, this, &Canvas::updateView);
    timer->start(100);
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

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
void Canvas::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key::Key_Up:
        scroll(QPoint(0, 20));
        break;
    case Qt::Key::Key_Down:
        scroll(QPoint(0, -20));
        break;
    case Qt::Key::Key_Left:
        scroll(QPoint(20, 0));
        break;
    case Qt::Key::Key_Right:
        scroll(QPoint(-20, 0));
        break;
    case Qt::Key::Key_Plus:
        scale(0.2);
        break;
    case Qt::Key::Key_Minus:
        scale(-0.2);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

void Canvas::scroll(QPoint point)
{
    manager->setOrigin(point);
    updateView();
}

void Canvas::scale(qreal scale)
{
    manager->setScale(scale);
    updateView();
}

void Canvas::updateView()
{
    manager->draw();
    repaint();
}
