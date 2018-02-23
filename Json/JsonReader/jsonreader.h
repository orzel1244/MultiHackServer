#ifndef JSONREADER_H
#define JSONREADER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

class JsonReader : public QObject
{
    Q_OBJECT
public:
    JsonReader(QString inputRaw);
    QString getType();
    QString getArgument(int i);
    int getSize();
private:
    QString m_type;
    QStringList m_arguments;
    QJsonObject* obj;
signals:

public slots:
};

#endif // JSONREADER_H
