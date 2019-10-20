#include "TcpClient.h"

#include <QDebug>
#include <QDataStream>
#include <QHostAddress>
#include <libs/GenericPrototypes/BitStream.h>
#include <libs/AtcrbsCoordinatePoint.h>
#include <libs/PeriodRepetitionAzimuth.h>
#include <libs/POIProtocol.h>
#include <libs/Azimuth.h>
#include <libs/CoordinatePoint.h>

#include <memory>

TcpClient::TcpClient(QObject *parent)
    : QObject (parent)
{
    qDebug() << "Client Started";

    m_socket = new QTcpSocket(this);

    m_socket->connectToHost(host, port);

    connect(m_socket, &QTcpSocket::connected, this, &TcpClient::onConnection);
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpClient::onMessage);
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpClient::socketError);
}

void TcpClient::onConnection()
{
    qDebug() << "Connected";
}

void TcpClient::onMessage()
{
    auto data = m_socket->readAll();

    std::vector<uint8_t> m_buffer;

    m_buffer.assign(data.begin(), data.end());

//    auto convertedData = static_cast<const uint8_t*>(static_cast<const void *>(data.data())); //Мутный каст (скопирован из pdp), нужно исправить
//    m_buffer.insert(m_buffer.end(), convertedData, convertedData + data.size());

    BitStream stream(m_buffer); //Возможно стоит отказаться и написать свой вариант (упрощенный)

    PVD::Header header;
    stream >> header;

    if (header.type == 350)
    {
        dsp::PeriodRepetitionAzimuth az;
        stream >> az;
        AzimuthDistributor::notifyConsumers(std::make_shared<Azimuth>(Azimuth::fromDegrees(az.azimuth.value())));
    }

    if (header.type == 391)
    {
        pvd::CoordinatePoint cp;
        stream >> cp;
        CoordinatePointDistributor::notifyConsumers(std::make_shared<pvd::CoordinatePoint>(cp));
    }
}

void TcpClient::socketError()
{
    qDebug() <<  "Socket Error" << m_socket->errorString();
}
