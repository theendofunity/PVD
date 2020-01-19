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

    std::vector<uint8_t> buffer;
};

#endif // DATAACCUMULATOR_H
