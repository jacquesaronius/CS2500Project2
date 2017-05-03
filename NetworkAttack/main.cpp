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

    return 0;
}

