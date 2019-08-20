#include "TcpClient.h"

#include <QDebug>
#include <QDataStream>
#include <QHostAddress>
#include <libs/GenericPrototypes/BitStream.h>
#include <libs/AtcrbsCoordinatePoint.h>

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

    auto convertedData = static_cast<const uint8_t*>(static_cast<const void *>(data.data()));

    m_buffer.insert(m_buffer.end(), convertedData, convertedData + data.size());

    BitStream stream(m_buffer);

    pdp::AtcrbsCoordinatePoint cp;
    stream >> cp;

    qDebug() << cp.bortNumber;
}

void TcpClient::socketError()
{
    qDebug() <<  "Socket Error" << m_socket->errorString();
}
