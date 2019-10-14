#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T13:25:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pvd
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

INCLUDEPATH += $${PROJECT_ROOT}/src
INCLUDEPATH += $${PROJECT_ROOT}/src/Distributors
INCLUDEPATH += $${PROJECT_ROOT}/libs/
INCLUDEPATH += $${PROJECT_ROOT}/libs/GenericPrototypes

SOURCES += \
        src/AzimuthLayer.cpp \
        src/Label.cpp \
        src/LabelLayer.cpp \
        src/Layer.cpp \
        libs/Azimuth.cpp \
        src/Canvas.cpp \
        src/CoordinatePoint.cpp \
        src/Distributors/AzimuthDistributor.cpp \
        src/Distributors/CoordinatePointDistributor.cpp \
        src/GridLayer.cpp \
        src/LayersManager.cpp \
        src/MainWindow.cpp \
        src/PVDSystem.cpp \
        src/PointContainer.cpp \
        src/PointLayer.cpp \
        src/main.cpp \
        src/TcpClient.cpp

HEADERS += \
        libs/CoordinatePoint.h \
        src/AzimuthLayer.h \
        src/Label.h \
        src/LabelLayer.h \
        src/Layer.h \
        libs/Azimuth.h \
        src/Canvas.h \
        src/CoordinatePoint.h \
        src/Distributors/AzimuthConsumer.h \
        src/Distributors/AzimuthDistributor.h \
        src/Distributors/CoordinatePointConsumer.h \
        src/Distributors/CoordinatePointDistributor.h \
        src/Distributors/IDistributor.h \
        libs/AtcrbsCoordinatePoint.h \
        libs/Answer.h \
        libs/POIProtocol.h  \
        libs/PeriodRepetitionAzimuth.h  \
        src/GridLayer.h \
        src/IItem.h \
        src/ILayer.h \
        src/LayersManager.h \
        src/MainWindow.h \
        src/PVDSystem.h \
        src/PointContainer.h \
        src/PointLayer.h \
        src/TcpClient.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
