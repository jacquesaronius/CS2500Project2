#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ctime>
#include <QQmlContext>
#include "controller.h"


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Controller controller;

    std::srand(time(NULL));

    engine.rootContext()->setContextProperty("controller", &controller);

    engine.rootContext()
                ->setContextProperty("MODE_ATTACK_BASE",
                                     Controller::MODE_ATTACK_BASE);
        engine.rootContext()
                ->setContextProperty("MODE_ATTACK_STATIC",
                                     Controller::MODE_ATTACK_STATIC);
        engine.rootContext()
                ->setContextProperty("MODE_ATTACK_DYNAMIC",
                                     Controller::MODE_ATTACK_DYNAMIC);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

