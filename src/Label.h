#ifndef LABEL_H
#define LABEL_H

#include "IItem.h"

#include <memory>

class CpMessage;

class Label : public IItem
{
public:
    Label(std::shared_ptr<CpMessage>);

    void draw(QPainter &painter, double scale) override;
    void calcPosition();
    void createTitle();

private:
    std::shared_ptr<CpMessage> cp;

    double x;
    double y;

    QStringList title;
};

#endif // LABEL_H
