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
                ->setContextProperty("MODE_STATIC_ROUTING",
                                     Controller::MODE_STATIC_ROUTING);
    engine.rootContext()
                ->setContextProperty("MODE_REACTIVE_ROUTING",
                                     Controller::MODE_REACTIVE_ROUTING);

    engine.rootContext()
                ->setContextProperty("MODE_BASE_ATTACK",
                                     Controller::MODE_BASE_ATTACK);
        engine.rootContext()
                ->setContextProperty("MODE_STATIC_ATTACK",
                                     Controller::MODE_STATIC_ATTACK);
        engine.rootContext()
                ->setContextProperty("MODE_REACTIVE_ATTACK",
                                     Controller::MODE_REACTIVE_ATTACK);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

