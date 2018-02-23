#include "database.h"

DataBase::DataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("accounts");
    if (!db.open()) { qDebug() << "ERROR WHILE OPENING DB"; }
    execute(
                "create table accounts (login varchar(20), password "
                "varchar(45), accountId varchar(45), enabled bool)");
}

DataBase::~DataBase() { db.close(); }

void DataBase::createAccount(QString login, QString password, QString id, bool enabled) {
    if (accountExist(login) == false) {
        QString cmd = QString(
                    "insert into accounts "
                    "values('%1', '%2', '%3', '%4')")
                .arg(login)
                .arg(password)
                .arg(id)
                .arg(enabled);
        execute(cmd);
    }
}


bool DataBase::accountExist(const QString& login) const {
    QSqlQuery query;
    QString cmd =
            QString("SELECT * FROM accounts WHERE login=\"%1\"").arg(login);
    query.exec(cmd);
    while (query.next()) {
        if (query.value(0).toString() == login) {
            // exist
            qDebug() << "return true";
            return true;
        }
    }
    qDebug() << "return false";
    return false;
}

int DataBase::getAccountId(const QString &login) const{
    QSqlQuery query;
    QString cmd =
            QString("SELECT * FROM accounts WHERE login=\"%1\"").arg(login);
    query.exec(cmd);
    while (query.next()) {
        if (query.value(0).toString() == login) {
            // exist
            return query.value(2).toInt();
        }
    }
    qDebug() << "Error while getting accountId of  " << login;
    return 404;  // error
}
QString DataBase::getPassword(QString login) {
    QSqlQuery query;
    QString cmd =
            QString("SELECT * FROM accounts WHERE login=\"%1\"").arg(login);
    query.exec(cmd);
    while (query.next()) {
        if (query.value(0).toString() == login) {
            // exist
            return query.value(1).toString();
        }
    }
    qDebug() << "Error while getting password of  " << login;
    return "error";  // error
}

bool DataBase::getAccountEnabled(QString login){
    QSqlQuery query;
    QString cmd =
            QString("SELECT * FROM accounts WHERE login=\"%1\"").arg(login);
    query.exec(cmd);
    while (query.next()) {
        if (query.value(0).toString() == login) {
            // exist
            return query.value(3).toBool();
        }
    }
    qDebug() << "Error while getting enabled of  " << login;
    return false;
}

void DataBase::execute(QString cmd) {
    QSqlQuery query;
    query.exec(cmd);
}
