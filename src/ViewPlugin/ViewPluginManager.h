#ifndef VIEWPLUGINMANAGER_H
#define VIEWPLUGINMANAGER_H

#include <QObject>
#include "ModuleBox.h"
#include "qqmlapplicationengine.h"
#include <QQuickWindow>
class  FreeKApplication;
///QML主界面和 QML引擎的初始化
class ViewPluginManager :public Module
{
    Q_OBJECT
public:
    ViewPluginManager (FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;

    QQmlApplicationEngine *  qmlEngine()         {return _qmlEngine;}
    QQuickWindow *           mainRootWindow();

    void initViewPlugin();
private:
    QQmlApplicationEngine *  _creatQmlEngine    ();
    QObject*                 _creatRootObject     ();
    void                     _creatMainWindow  ();
    ModuleBox *              _moduleBox;
    //qml
    QQmlApplicationEngine *  _qmlEngine;
    QQuickWindow *           _mainRootWindow;
};

#endif // VIEWPLUGINMANAGER_H
