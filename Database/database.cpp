#include "database.h"

Database::Database(QObject *parent) : QObject(parent){;
                                                      if (!accountsDir.exists())
                                                          accountsDir.mkpath(".");

                                                     }

bool Database::createAccount(User *user){
    if(accountExists(user->name()))
        return false;
    QString fPath = QString("%1/%2%3").arg(accountsDir.path()).arg(user->name()).arg(format);
    QFile file(fPath);
    qDebug() << file.fileName();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream stream(&file);
    stream << user->getJson();
    file.close();
    if(file.error())
        return false;
    return true;
}

bool Database::accountExists(QString userName){
    QString fPath = QString("%1/%2%3").arg(accountsDir.path()).arg(userName).arg(format);
    return QFile(fPath).exists();
}

bool Database::updateAccount(QString oldUserName, User *newUser){
    QString fPath = QString("%1/%2%3").arg(accountsDir.path()).arg(oldUserName).arg(format);
    QFile file(fPath);
    if(file.exists()){
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;
        QTextStream stream(&file);
        stream << newUser->getJson();
        if(file.error())
            return false;
        file.rename(newUser->name());
        return true;
    }
}

User *Database::getAccount(QString name){
    QString fPath = QString("%1/%2%3").arg(accountsDir.path()).arg(name).arg(format);
    QFile file(fPath);
    if(file.exists()){
        file.open(QIODevice::ReadWrite);
        QString data = QString::fromStdString(file.readAll().toStdString());
        User *u = new User(data);
        return u;
    }
}
