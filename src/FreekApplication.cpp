#include "FreekApplication.h"
#include <QQmlApplicationEngine>
#include "ModuleBox.h"

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

}

//全局单例接口
FreeKApplication* FreeKApp(void) {
    return FreeKApplication::_app;
}

bool FreeKApplication::checkErrorState() {

     return true;
}

bool FreeKApplication::event(QEvent *e) {
     Q_UNUSED(e)
     return true;
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


}
