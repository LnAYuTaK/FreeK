#include "FreekApplication.h"
#include "ModuleBox.h"
#include "ViewPluginManager.h"
#include "ViewSetup.h"
FreeKApplication* FreeKApplication::_app = nullptr;
FreeKApplication::FreeKApplication(int &argc, char* argv[])
   :QApplication(argc, argv)
   ,_moduleBox(nullptr)
   ,_qmlAppEngine (nullptr)
{
     _app = this;
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




//QObject* FreeKApplication::_creatRootObject() {
//    if(_qmlAppEngine!=nullptr){
//        return _qmlAppEngine->rootObjects()[0];
//    }
//    else{
//        return nullptr;
//    }
//}

void FreeKApplication::initAppCommon() {

//qmlRegisterSingletonType<ViewSetup>     ("FreeK.ViewSetup",    1, 0, "ViewSetup",  ViewSetup);





}

void FreeKApplication::initAppView() {
    //_qmlAppEngine = FreeKApp()->moduleBox()->viewPiuginManager()->createdQmlEngine();
    FreeKApp()->moduleBox()->viewPiuginManager()->initViewPlugin();
}







