#ifndef VIEWPLUGINMANAGER_H
#define VIEWPLUGINMANAGER_H

#include <QObject>
#include "ModuleBox.h"
#include "qqmlapplicationengine.h"
#include <QQuickWindow>
class  FreeKApplication;
//主界面
class ViewPluginManager :public Module
{
    Q_OBJECT
public:
    ViewPluginManager (FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;

    QQmlApplicationEngine *  createdQmlEngine    ();
    QObject*                 creatRootObject     ();

private:
   // QQuickWindow *         _createdMainWindow  ();
    void                     _createdMainWindow  ();
    ModuleBox *              _moduleBox;
    QQmlApplicationEngine *  _qmlEngine;
    QQuickWindow *           _mainRootWindow;
};

#endif // VIEWPLUGINMANAGER_H
