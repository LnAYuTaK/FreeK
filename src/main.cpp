#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "FreekApplication.h"
int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    FreeKApplication* app = new FreeKApplication(argc, argv);
    Q_CHECK_PTR(app);
    if(app->checkErrorState()){
         app->exec();
    }
    app->deleteLater();
}
