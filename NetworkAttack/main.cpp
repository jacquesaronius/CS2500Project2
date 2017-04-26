#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ctime>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    std::srand(time(NULL));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
