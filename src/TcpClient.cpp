#include "TcpClient.h"

#include <QDebug>
#include <QDataStream>
#include <QHostAddress>

#include <libs/Azimuth.h>

#include "libs/HeaderMessage.h"
#include "libs/CpMessage.h"
#include "libs/AzimuthMessage.h"

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

    accumulator.setData(data);

    QDataStream stream(data);

    HeaderMessage header;

    while(accumulator.getFrame(stream, header))
    {
        if (header.type == 350)
        {
            AzimuthMessage az;
            stream >> az;
            AzimuthDistributor::notifyConsumers(std::make_shared<Azimuth>(Azimuth::fromDegrees(az.azimuth)));
        }

        if (header.type == 391)
        {
            CpMessage cp;
            stream >> cp;
            CoordinatePointDistributor::notifyConsumers(std::make_shared<CpMessage>(cp));
        }
    }
}

void TcpClient::socketError()
{
    qDebug() <<  "Socket Error" << m_socket->errorString();
}
