#pragma once

#include <QWidget>
#include <QPixmap>

class Canvas : public QWidget
{
public:
    Canvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPixmap m_base;
    QPoint center = QPoint();
};

