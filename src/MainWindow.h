#pragma once

#include <QMainWindow>
#include <memory>

class PVDSystem;

class PointContainer;
class TcpClient;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    void createMainWindow();

private:
    std::shared_ptr<PointContainer> points = nullptr;
    TcpClient *tcpClient = nullptr;

    PVDSystem *pvd = nullptr;
};

