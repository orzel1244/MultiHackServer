#ifndef ROUTINGMANAGER_H
#define ROUTINGMANAGER_H

#include <QObject>
#include <./Corw/crow_all.h>
#include <./Database/database.h>
#include <./Json/JsonGenerator/jsongenerator.h>
#include <./Json/JsonReader/jsonreader.h>
#include <QDebug>

class RoutingManager : public QObject {
    Q_OBJECT
public:
    explicit RoutingManager();
signals:

};

#endif // ROUTINGMANAGER_H
