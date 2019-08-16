#include "MainWindow.h"
#include <QApplication>

#include "RabbitMQClient.h"
#include "TcpClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    TcpClient *client = new TcpClient;

    MainWindow w;
//    w.show();

    return a.exec();
}
