#include "MainWindow.h"
#include <QApplication>

#include "RabbitMQClient.h"
#include "amqpcpp.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RabbitMQClient client;

    // create a AMQP connection object
    AMQP::Connection connection(&client, AMQP::Login("guest","guest"), "/");

    // and create a channel
    AMQP::Channel channel(&connection);

    // use the channel object to call the AMQP method you like
    channel.declareExchange("my-exchange", AMQP::fanout);
    channel.declareQueue("my-queue");
    channel.bindQueue("my-exchange", "my-queue", "my-routing-key");

    MainWindow w;
    w.show();

    return a.exec();
}
