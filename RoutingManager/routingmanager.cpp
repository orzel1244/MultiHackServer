#include "routingmanager.h"

RoutingManager::RoutingManager(){
    crow::SimpleApp app; qDebug() << "Routing Manager started";


    // TODO: enabled zawsze zwraca false! dlatego ze 0 / 1
    // sadly the lib don't allowe me to use SimpleApp as pointer
    CROW_ROUTE(app, "/")([](){
        return crow::response(404);
    });
    CROW_ROUTE(app, "/auth/login")
            .methods("POST"_method)
            ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x) {return crow::response(400);}
        QString login = QString::fromStdString(x["login"].s());
        QString password = QString::fromStdString(x["password"].s());
        qDebug() << password;
        password = QString::fromStdString(QCryptographicHash::hash(QByteArray::fromStdString(password.toStdString()), QCryptographicHash::Sha3_512	).toHex().toStdString());
        crow::json::wvalue v;
        qDebug() << "compare"<<password;
        qDebug() << "with"<<Database::get().getAccount(login)->password();
        if(Database::get().accountExists(login) && Database::get().getAccount(login)->password() == password){
            User *user = Database::get().getAccount(login);
            qDebug() << user->enabled();
            if(user->enabled()){
                v["message"] = "Login Success!";
                v["accountId"] = user->accountId().toStdString();
                v["enabled"] = user->enabled();
                qDebug() << "User login:"<<user->name();
            } else {
                v["message"] = "Your account is disabled!";
            }
        } else {
            v["message"] = "Incorrect!";
        }
        return crow::response(v);
    });

    CROW_ROUTE(app, "/auth/register")
            .methods("POST"_method)
            ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x) {return crow::response(400);}
        QString login = QString::fromStdString(x["login"].s());
        QString password = QString::fromStdString(x["password"].s());
        QString accId = QString::fromStdString(x["accountId"].s());
        crow::json::wvalue v;
        if(Database::get().accountExists(login) == false){
            Database::get().createAccount(new User(login,password,accId,false));
            v["message"] = "Register Success!";
        } else {
            v["message"] = "This account already exists";
        }
        return crow::response(v);
    });

    app.port(8080).multithreaded().run();
}
