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

//注册完之后运行
void  ViewPluginManager::_creatMainWindow () {
    //核心视图显示
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
//对外提供mainRootWindow接口
QQuickWindow* ViewPluginManager::mainRootWindow() {
    if(!_mainRootWindow) {
        _mainRootWindow = qobject_cast<QQuickWindow*>(_creatRootObject());
    }
    return _mainRootWindow;
}
//初始化视图插件
void  ViewPluginManager::initViewPlugin() {
    this->_creatQmlEngine();
    this->_creatMainWindow();
}
//加载qml界面













