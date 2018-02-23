#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QtSql>

class DataBase : public QObject {
    Q_OBJECT

private:
    DataBase(const DataBase&);

public:
    DataBase();
    static DataBase& getDatabase() {
        static DataBase database;
        return database;
    }

    ~DataBase();
    void createAccount(QString login, QString password, QString id, bool enabled);
    bool accountExist(const QString& login) const;
    int getAccountId(const QString& login) const;
    QString getPassword(QString login);
    bool getAccountEnabled(QString login);
private:
    void execute(QString cmd);
    QSqlDatabase db;
signals:

public slots:
};

#endif  // DATABASE_H
