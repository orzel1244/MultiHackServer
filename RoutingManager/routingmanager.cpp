#include "routingmanager.h"

RoutingManager::RoutingManager(){
    crow::SimpleApp app; qDebug() << "Routing Manager started";
    // sadly the lib don't allowe me to use SimpleApp as pointer

    CROW_ROUTE(app, "/")([](){
        return crow::response(404);
    });
    CROW_ROUTE(app, "/auth/login") // {"login":"orzel1244", "password":"password"}
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x) {return crow::response(400);}
        QString login = QString::fromStdString(x["login"].s());
        QString password = QString::fromStdString(x["password"].s());
        crow::json::wvalue v;
        if(DataBase::getDatabase().accountExist(login) && DataBase::getDatabase().getPassword(login) == password){
            if(DataBase::getDatabase().getAccountEnabled(login)){
            v["message"] = "Success!";
            v["accountId"] = DataBase::getDatabase().getAccountId(login);
            v["enabled"] = DataBase::getDatabase().getAccountEnabled(login);
            } else {
                v["message"] = "Your account is disabled!";
            }
        } else {
            v["message"] = "Incorrect!";
        }
        return crow::response(v);
    });

    CROW_ROUTE(app, "/auth/register") // {"login":"myAccount", "password":"myPass", "accountId":"101011"}
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x) {return crow::response(400);}
        QString login = QString::fromStdString(x["login"].s());
        QString password = QString::fromStdString(x["password"].s());
        QString accId = QString::fromStdString(x["accountId"].s());
        crow::json::wvalue v;
        if(DataBase::getDatabase().accountExist(login) == false){
            DataBase::getDatabase().createAccount(login,password,accId,false);
            v["message"] = "Success!";
        } else {
            v["message"] = "This account already exists";
        }
        return crow::response(v);
    });

    app.port(8080).multithreaded().run();
}
