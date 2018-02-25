#ifndef ROUTINGMANAGER_H
#define ROUTINGMANAGER_H

#include <QObject>
#include <./Corw/crow_all.h>
#include <./Database/database.h>
#include <./User/user.h>
#include <QCryptographicHash>
#include <QDebug>

class RoutingManager : public QObject {
    Q_OBJECT
public:
    explicit RoutingManager();

signals:

};

#endif // ROUTINGMANAGER_H
