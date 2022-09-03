#ifndef FREEKQMLGLOBAL_H
#define FREEKQMLGLOBAL_H

#include <QObject>
#include "ModuleBox.h"
class FreeKApplication;

///
///单例对象注册到QML
///
class FreeKQmlGlobal : public Module
{
    Q_OBJECT
public:
    FreeKQmlGlobal(FreeKApplication *app , ModuleBox  * moduleBox);

    void  setModuleBox(ModuleBox  * moduleBox)override ;

//    Q_PROPERTY(QString              appName                 READ    appName                 CONSTANT)
//    Q_PROPERTY(LinkManager*         linkManager             READ    linkManager             CONSTANT)
//    Q_PROPERTY(MultiVehicleManager* multiVehicleManager     READ    multiVehicleManager     CONSTANT)
//    Q_PROPERTY(QGCMapEngineManager* mapEngineManager        READ    mapEngineManager        CONSTANT)


//    QString                 appName             ()  { return qgcApp()->applicationName(); }
//    LinkManager*            linkManager         ()  { return _linkManager; }
//    MultiVehicleManager*    multiVehicleManager ()  { return _multiVehicleManager; }
//    QGCMapEngineManager*    mapEngineManager    ()  { return _mapEngineManager; }
//    QGCPositionManager*     qgcPositionManger   ()  { return _qgcPositionManager; }
//    MissionCommandTree*     missionCommandTree  ()  { return _missionCommandTree; }

private:
    ModuleBox *          _moduleBox;
    SettingsManager*     _settingsManager;
    MapEngineManager *   _mapEngineManager;
    ViewPluginManager *  _viewPiuginManager;
    ViewSetup *          _viewSetup;
    PositionManager *    _positionManager;

};

#endif // FREEKQMLGLOBAL_H
