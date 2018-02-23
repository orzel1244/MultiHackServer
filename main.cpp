#include <QCoreApplication>
#include "Corw/crow_all.h"
#include "RoutingManager/routingmanager.h"
#include "Database/database.h"
#include <QTimer>

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    RoutingManager manager;
    return a.exec();
}
