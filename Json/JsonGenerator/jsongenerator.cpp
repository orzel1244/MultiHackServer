#include "jsongenerator.h"

JsonGenerator::JsonGenerator(QString type, QStringList args){
    m_type = type;
    m_args = args;
}

JsonGenerator::JsonGenerator(){

}

QString JsonGenerator::output() const {
    QString values;
    for(int i=0; i<m_args.size(); i++){
        if (i != m_args.size()-1){
            values.append(QString("\"%1\",").arg(m_args[i]));
        } else {
            values.append(QString("\"%1\"").arg(m_args[i]));
        }
    }
    return QString("{\"type\":\"%1\",\"values\":[%2]}").arg(m_type).arg(values);
}

void JsonGenerator::setType(const QString &type){
    m_type = type;
}

void JsonGenerator::addArgument(const QString &arg){
    m_args.append(arg);
}
