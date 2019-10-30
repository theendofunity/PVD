#include "DataAccumulator.h"

#include "libs/HeaderMessage.h"

#include <QDebug>

DataAccumulator::DataAccumulator()
{

}

void DataAccumulator::setData(QByteArray &data)
{
    frame.insert(frame.end(), data.begin(), data.end());
}

bool DataAccumulator::getFrame(QDataStream &stream, HeaderMessage &header)
{
    if (frame.size() < 4)
        return false;

    stream >> header;

    if (frame.size() < header.size)
        return false;

    frame.erase(frame.begin(), frame.begin() + header.size);
    return true;
}
