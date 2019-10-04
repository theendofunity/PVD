#pragma once

#include <QWidget>
#include <QPixmap>

#include <memory>


class LayersManager;

class Canvas : public QWidget
{
public:
    Canvas(std::shared_ptr<LayersManager> manager, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateView();
private:
    QPixmap m_base;
    QPoint center = QPoint();

    std::shared_ptr<LayersManager> manager;
};

