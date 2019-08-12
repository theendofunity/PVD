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
private:
    QTcpSocket *m_socket = nullptr;
};

#endif // TCPCLIENT_H
