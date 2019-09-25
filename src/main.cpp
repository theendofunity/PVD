#include "MainWindow.h"
#include <QApplication>

#include "TcpClient.h"
#include "PointContainer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PointContainer *container = new PointContainer;
    TcpClient *client = new TcpClient;

    static_cast<CoordinatePointDistributor*>(client)->addConsumer(container);
    static_cast<AzimuthDistributor*>(client)->addConsumer(container);

    MainWindow w;
    w.show();

    return a.exec();
}
