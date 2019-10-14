#ifndef LABEL_H
#define LABEL_H

#include "IItem.h"

#include <memory>

namespace pvd
{
class CoordinatePoint;
}

class Label : public IItem
{
public:
    Label(std::shared_ptr<pvd::CoordinatePoint>);

    void draw(QPainter &painter, double scale) override;
    void calcPosition();
    void createTitle();

private:
    std::shared_ptr<pvd::CoordinatePoint> cp;

    double x;
    double y;

    QStringList title;
};

#endif // LABEL_H
