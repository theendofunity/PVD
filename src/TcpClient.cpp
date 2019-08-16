#include "TcpClient.h"

#include <QDebug>
#include <QDataStream>
#include <QHostAddress>

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
    QDataStream stream(m_socket);

    uint16_t nextblock = 0;
    while (m_socket->bytesAvailable())
    {
        stream >> nextblock;
    }
    qDebug() << nextblock;
}

void TcpClient::socketError()
{
    qDebug() <<  "Socket Error" << m_socket->errorString();
}
