#include "MainWindow.h"

#include "PointContainer.h"
#include "TcpClient.h"
#include "PVDSystem.h"
#include "Canvas.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(500, 500);

    tcpClient = new TcpClient(this);

    pvd = new PVDSystem();

    createMainWindow();

    pvd->associateWith(dynamic_cast<AzimuthDistributor*>(tcpClient));
    pvd->associateWith(dynamic_cast<CoordinatePointDistributor*>(tcpClient));

    showMaximized();
}

MainWindow::~MainWindow()
{
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
