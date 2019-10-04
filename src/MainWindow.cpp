#include "MainWindow.h"

#include "PointContainer.h"
#include "TcpClient.h"
#include "PVDSystem.h"
#include "Canvas.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    points = std::make_shared<PointContainer>();

    tcpClient = new TcpClient;

    //Подписка на сообщения
    static_cast<CoordinatePointDistributor*>(tcpClient)->addConsumer(points.get());
    static_cast<AzimuthDistributor*>(tcpClient)->addConsumer(points.get());

    pvd = new PVDSystem;

    createMainWindow();

    showMaximized();
}

MainWindow::~MainWindow()
{
    delete tcpClient;
    delete pvd;
}

void MainWindow::createMainWindow()
{
    QWidget* mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(pvd->getCanvas());
}
