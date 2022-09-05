#include <QtQml>

#include "FreekApplication.h"
#include "ModuleBox.h"
#include "ViewPluginManager.h"
#include "ViewSetup.h"
#include "FreeKQmlGlobal.h"
#include "MapEngineManager.h"
#include "PositionManager.h"
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
//-----------------------------------------------------------------------------

FreeKApplication::~FreeKApplication()
{
    _moduleBox->deleteLater();
}

//-----------------------------------------------------------------------------

//全局单例接口
FreeKApplication* FreeKApp(void)
{
    return FreeKApplication::_app;
}

//-----------------------------------------------------------------------------


bool FreeKApplication::checkErrorState()
{
     return false;
}

//-----------------------------------------------------------------------------
//close Windows
bool FreeKApplication::event(QEvent *e)
{
     Q_UNUSED(e)
     if (e->type() == QEvent::Quit){
       FreeKApp()->moduleBox()->viewPluginManager()->mainRootWindow()->close();
       this->exit();
     }
     return QApplication::event(e);
}

//-----------------------------------------------------------------------------
//QObject *(*callbackRest)(QQmlEngine *, QJSEngine *) =  freeKQmlGlobalRegist(nullptr,nullptr);
static QObject *freeKQmlGlobalRegist(QQmlEngine*, QJSEngine*)
{
     FreeKQmlGlobal   *freeKQmlGlobal  =  new FreeKQmlGlobal(FreeKApp(),FreeKApp()->moduleBox());
     freeKQmlGlobal->setModuleBox(FreeKApp()->moduleBox());
     return  qobject_cast<QObject *>(freeKQmlGlobal);
}

void FreeKApplication::initAppCommon()
{
   // freeKQmlGlobalRegist(nullptr,nullptr);

    qmlRegisterUncreatableType<PositionManager>  ("FreeK.PositionManager",   1, 0, "PositionManager",  "Reference only");

    qmlRegisterUncreatableType<MapEngineManager>  ("FreeK.MapEngineManager",  1, 0, "MapEngineManager",  "Reference only");

    qmlRegisterSingletonType<FreeKQmlGlobal>("FreeK",1,0,"FreeK",freeKQmlGlobalRegist);
    //注册单例//
}
//-----------------------------------------------------------------------------

void FreeKApplication::initAppView()
{
    FreeKApp()->moduleBox()->viewPluginManager()->initViewPlugin();
}

//-----------------------------------------------------------------------------








