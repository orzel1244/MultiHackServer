#ifndef USER_H
#define USER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QCryptographicHash>
#include <QDebug>

class User : public QObject
{
    Q_OBJECT
public:
    User();
    User(QString name, QString password, QString accountId, bool enabled);
    User(QString json);

    QString getJson();
    QString name() const;
    void setName(const QString &name);

    QString password() const;
    void setPassword(const QString &password);

    QString accountId() const;
    void setAccountId(const QString &accountId);

    bool enabled() const;
    void setEnabled(const bool &enabled);

private:
    QString m_name;
    QString m_password;
    QString m_accountId;
    bool m_enabled;

public slots:
};

#endif // USER_H
