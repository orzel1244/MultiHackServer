#include "jsonreader.h"

JsonReader::JsonReader(QString inputRaw){
    QJsonDocument doc = QJsonDocument::fromJson(inputRaw.toUtf8());
    bool error=false;

    if (!doc.isNull()) {
        if (!doc.isObject()) {
            qDebug() << "Document is not an object" << endl;
            error=true;
        }
    } else {
        qDebug() << "Invalid JSON...\n" << inputRaw << endl;
        error=true;
    }
    if (!error){
        obj = new QJsonObject(doc.object());
    }
}

QString JsonReader::getType(){
    return obj->value("type").toString();
}

QString JsonReader::getArgument(int i){
    QJsonArray array = obj->value("values").toArray();
    return array.at(i).toString();
}

int JsonReader::getSize(){
    return m_arguments.size();
}
