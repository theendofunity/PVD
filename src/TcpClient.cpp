#include "TcpClient.h"

#include <QDebug>
#include <QDataStream>
#include <QHostAddress>
#include <libs/GenericPrototypes/BitStream.h>
#include <libs/AtcrbsCoordinatePoint.h>
#include <libs/PeriodRepetitionAzimuth.h>
#include <libs/POIProtocol.h>

TcpClient::TcpClient(QObject *parent)
    : QObject (parent)
{
    qDebug() << "Client Started";

    m_socket = new QTcpSocket(this);

    m_socket->connectToHost(QHostAddress(host), port);

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
    qDebug() << "Type" << header.type;

    if (header.type == 25)
    {
        dsp::PeriodRepetitionAzimuth az;
        stream >> az;
        qDebug() << "AZIMUTH" << az.azimuth;
    }

    if (header.type == 91)
    {
        pdp::AtcrbsCoordinatePoint cp;
        stream >> cp;
        qDebug() << "CP" << cp.bortNumber;
    }
}

void TcpClient::socketError()
{
    qDebug() <<  "Socket Error" << m_socket->errorString();
}
