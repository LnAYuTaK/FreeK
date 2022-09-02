#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FreekApplication.h"
#include <QtPlugin>
int main(int argc, char *argv[])
{
    //加载地图插件
    Q_IMPORT_PLUGIN(QGeoServiceProviderFactoryFreeK);



#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    FreeKApplication* app = new FreeKApplication(argc, argv);
    Q_CHECK_PTR(app);
    if(app->checkErrorState()){
        app->exec();
        return -1;
    }

    {
    //插件初始化
    app->initAppCommon();
    //视图初始化
    app->initAppView();
    app->exec();
    }

    qDebug() <<"Program exit";
}
