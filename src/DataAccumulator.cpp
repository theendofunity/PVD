#include "DataAccumulator.h"

#include "libs/HeaderMessage.h"

#include <QDebug>

DataAccumulator::DataAccumulator()
{

}

void DataAccumulator::setData(QByteArray &data)
{
    buffer.insert(buffer.end(), data.begin(), data.end());
}

bool DataAccumulator::getFrame(QDataStream &stream, HeaderMessage &header)
{
    if (buffer.size() < 4)
        return false;

    stream >> header;

    if (buffer.size() < header.size)
        return false;

    buffer.erase(buffer.begin(), buffer.begin() + header.size);
    return true;
}
