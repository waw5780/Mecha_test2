#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

#include <main_view_model.h>
#include <feeder_minimum_find_tab_view_model.h>
#include <feeder_performance_test_tab_view_model.h>
#include <devices/scale.h>
#include <models/main_control_model.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ViewModels::MainViewModel *mainUi = new ViewModels::MainViewModel();

    ViewModels::FeederPerforManceTestTabViewModel *feederPerformance = new
    ViewModels::FeederPerforManceTestTabViewModel();

    ViewModels::FeederMinimumFindTabViewModel *feederMini = new
    ViewModels::FeederMinimumFindTabViewModel();

    engine.rootContext()->setContextProperty("mainUi", mainUi);
    engine.rootContext()->setContextProperty("feederPerformance", feederPerformance);
    engine.rootContext()->setContextProperty("feederMini", feederMini);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
