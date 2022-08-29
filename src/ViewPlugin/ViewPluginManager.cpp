#include "ViewPluginManager.h"
#include "FreekApplication.h"
//qml引擎 创建Mainwindows
ViewPluginManager::ViewPluginManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
    ,_qmlEngine(nullptr)
    ,_mainRootWindow(nullptr)
{

}

void ViewPluginManager::setModuleBox(ModuleBox  *moduleBox) {
   _moduleBox = moduleBox;
}

QQmlApplicationEngine *ViewPluginManager::_creatQmlEngine() {
    _qmlEngine =new  QQmlApplicationEngine(this);
    return _qmlEngine;
}

//QQuickWindow *ViewPluginManager::_createdMainWindow()
//{
//    _mainRootWindow = qobject_cast<QQuickWindow*>(creatRootObject());
//    return _mainRootWindow;
//}

//*一定要保证
void  ViewPluginManager::_creatMainWindow () {

   // _qmlEngine.load()
   _qmlEngine->addImportPath("qrc:/qml");
   _qmlEngine->load("qrc:/qml/MainRootWindow.qml");
}

QObject* ViewPluginManager::_creatRootObject() {
    if(_qmlEngine!=nullptr){
        return _qmlEngine->rootObjects()[0];
    }
    else{
        return nullptr;
    }
}
void   ViewPluginManager::initViewPlugin()
{
    this->_creatQmlEngine();
    this->_creatMainWindow();
}










