#ifndef RABBITMQCLIENT_H
#define RABBITMQCLIENT_H

#include "amqpcpp.h"

class RabbitMQClient : public AMQP::ConnectionHandler
{
public:
    RabbitMQClient();
};

#endif // RABBITMQCLIENT_H
