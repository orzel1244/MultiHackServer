#include <QtCore/QCoreApplication>
#include "Corw/crow_all.h"
#include "RoutingManager/routingmanager.h"
#include "Database/database.h"
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    RoutingManager manager;
    return a.exec();
}
