#ifndef TCPCLIENT_H
#define TCPCLIENT_H


#include <QObject>

#include <QtNetwork/QTcpSocket>

#include "Distributors/AzimuthDistributor.h"
#include "Distributors/CoordinatePointDistributor.h"

class TcpClient : public QObject
                , public AzimuthDistributor
                , public CoordinatePointDistributor
{
    Q_OBJECT

public:
    TcpClient(QObject *parent = nullptr);

    void onConnection();
    void onMessage();
    void socketError();
private:
    QTcpSocket *m_socket = nullptr;
    const uint16_t port = 10800;
    QString host = "192.168.0.109";
};

#endif // TCPCLIENT_H
