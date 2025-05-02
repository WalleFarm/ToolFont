#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include<QQuickItem>
#include "MainInterface.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QGuiApplication app(argc, argv);
    
    MainInterface main_interface;
    
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    
     engine.rootContext()->setContextProperty("theMainInterface", &main_interface);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    
    return app.exec();
}
