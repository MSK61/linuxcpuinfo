#include "modelservices.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    using namespace ModelServices;
    static const QVariantList coreLst = GetProcessors();
    int execRes;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(
                "cores", QVariant::fromValue(coreLst));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    execRes = app.exec();
    DeleteCoreList(coreLst);
    return execRes;

}
