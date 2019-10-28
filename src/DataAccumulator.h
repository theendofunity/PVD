#ifndef DATAACCUMULATOR_H
#define DATAACCUMULATOR_H

#include <QByteArray>
#include <vector>

class HeaderMessage;

class DataAccumulator
{
public:
    DataAccumulator();

    void setData(QByteArray &data);

    bool getFrame(QDataStream &stream, HeaderMessage &header);
private:
    QByteArray buffer;

    std::vector<uint8_t> frame;
};

#endif // DATAACCUMULATOR_H
