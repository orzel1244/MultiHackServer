#include "user.h"

User::User(QString name, QString password, QString accountId, bool enabled){
    setName(name);
    setPassword(password);
    setAccountId(accountId);
    setEnabled(enabled);
}

User::User(QString json){
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject obj = doc.object();
    setName(obj.value("name").toString());
    m_password = obj.value("password").toString(); // not setPassword() because it was hashing 2 times xd
    setAccountId(obj.value("accountId").toString());
    setEnabled(obj.value("enabled").toInt());
}

QString User::getJson(){
    return QString(
                "{\n"
                "\"name\":\"%1\",\n"
                "\"password\":\"%2\",\n"
                "\"accountId\":\"%3\",\n"
                "\"enabled\":%4\n"
                "}")
            .arg(name())
            .arg(password())
            .arg(accountId())
            .arg(enabled());
}
QString User::name() const{ return m_name;}
void User::setName(const QString &name){ m_name = name;}

QString User::password() const{ return m_password;}
void User::setPassword(const QString &password){
    m_password =  QString::fromStdString(QCryptographicHash::hash(QByteArray::fromStdString(password.toStdString()), QCryptographicHash::Sha3_512	).toHex().toStdString());

}

QString User::accountId() const{ return m_accountId;}
void User::setAccountId(const QString &accountId){ m_accountId = accountId;}

bool User::enabled() const{ return m_enabled;}
void User::setEnabled(const bool &enabled){ m_enabled = enabled;}
