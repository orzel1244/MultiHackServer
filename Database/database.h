#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <./User/user.h>
#include <QTextStream>
#include <QCryptographicHash>

class Database : public QObject{
    Q_OBJECT
private:
    Database(QObject *parent = nullptr);
public:
    static Database& get(){
        static Database db;
        return db;
    }
    bool createAccount(User* user);
    bool accountExists(QString userName);
    bool updateAccount(QString oldUserName, User* newUser);
    User* getAccount(QString name);
private:
    QDir accountsDir =  QDir("accounts");
    QString format =    QString(".json");

public slots:
};

#endif // DATABASE_H
