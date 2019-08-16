#ifndef TCPCLIENT_H
#define TCPCLIENT_H


#include <QObject>

#include <QtNetwork/QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT

public:
    TcpClient(QObject *parent = nullptr);

    void onConnection();
    void onMessage();
    void socketError();
private:
    QTcpSocket *m_socket = nullptr;
    const uint16_t port = 10700;
    QString host = "127.0.0.1";
};

#endif // TCPCLIENT_H
