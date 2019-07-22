#ifndef RABBITMQCLIENT_H
#define RABBITMQCLIENT_H

#include "amqpcpp.h"

class RabbitMQClient : public AMQP::ConnectionHandler
{
public:
    RabbitMQClient();

    virtual void onData(AMQP::Connection *connection, const char *data, size_t size);
    virtual void onReady(AMQP::Connection *connection);
    virtual void onError(AMQP::Connection *connection, const char *message);
    virtual void onClosed(AMQP::Connection *connection) ;
};

#endif // RABBITMQCLIENT_H
