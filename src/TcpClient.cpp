#include "TcpClient.h"

#include <QDebug>
#include <QDataStream>

TcpClient::TcpClient(QObject *parent)
    : QObject (parent)
{
    m_socket = new QTcpSocket(this);

    m_socket->connectToHost("localhost", 5500);

    connect(m_socket, &QTcpSocket::connected, this, &TcpClient::onConnection);
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpClient::onMessage);
}

void TcpClient::onConnection()
{
    qDebug() << "Connected";
}

void TcpClient::onMessage()
{
    QDataStream stream(m_socket);
}
