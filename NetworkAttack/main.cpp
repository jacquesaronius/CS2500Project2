#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ctime>
#include "controller.h"

int main(int argc, char *argv[])
{

    //QGuiApplication app(argc, argv);

    //QQmlApplicationEngine engine;

    std::srand(time(NULL));

    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //return app.exec();
    Controller c;
    int choice =0;
    cin>>choice;
    switch(choice){
        case 0: c.StaticRouting();
                break;
        case 1: c.ReActiveRouting();
                break;
    }

    return 0;
}

