#include "FreekApplication.h"
#include "ModuleBox.h"
#include "ViewPluginManager.h"
#include "ViewSetup.h"
#include  "MapEngineManager.h"
#include <QtQml>
#include "ScreenTool.h"
FreeKApplication* FreeKApplication::_app = nullptr;
FreeKApplication::FreeKApplication(int &argc, char* argv[])
   :QApplication(argc, argv)
   ,_moduleBox(nullptr)
   ,_qmlAppEngine (nullptr)
{
     _app = this;
     this->setApplicationName("FreeK");
     //实例化工具插件
     _moduleBox = new ModuleBox(this);
     _moduleBox->setChildBoxes();
}

FreeKApplication::~FreeKApplication() {
    _moduleBox->deleteLater();
}

//全局单例接口
FreeKApplication* FreeKApp(void) {
    return FreeKApplication::_app;
}

bool FreeKApplication::checkErrorState() {

     return false;
}



//close Windows
bool FreeKApplication::event(QEvent *e) {
     Q_UNUSED(e)
     if (e->type() == QEvent::Quit){
       FreeKApp()->moduleBox()->viewPiuginManager()->mainRootWindow()->close();
       this->exit();
     }
     return QApplication::event(e);
}


void FreeKApplication::initAppCommon() {
    //全局单例注册


    //统一注册到qml
    //
    //qmlRegisterUncreatableType  <MapManager> ("FreeK.MapManager",   1, 0, "MapManager", "Reference only");
    //qmlRegisterType<MapManager>      ("FreeK.MapManager",1, 0, "MapManager");
}

void FreeKApplication::initAppView() {
    //_qmlAppEngine = FreeKApp()->moduleBox()->viewPiuginManager()->createdQmlEngine();
    FreeKApp()->moduleBox()->viewPiuginManager()->initViewPlugin();
}







