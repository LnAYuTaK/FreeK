#ifndef FREEKQMLGLOBAL_H
#define FREEKQMLGLOBAL_H

#include <QObject>
#include "ModuleBox.h"
class MapEngineManager;
class FreeKApplication;
class ViewPluginManager;
class PositionManager;
class ViewSetup;
///
///单例对象注册到QML
///
class FreeKQmlGlobal : public Module
{
    Q_OBJECT
    Q_DISABLE_COPY(FreeKQmlGlobal)
public:
    FreeKQmlGlobal(FreeKApplication *app , ModuleBox  * moduleBox);

    void  setModuleBox(ModuleBox  * moduleBox)override ;

    Q_PROPERTY(SettingsManager *    settingManager          READ    settingManager          CONSTANT)
    Q_PROPERTY(MapEngineManager *   mapEngineManager        READ    mapEngineManager        CONSTANT)
    Q_PROPERTY(ViewPluginManager *  viewPluginManager       READ    viewPluginManager       CONSTANT)
    Q_PROPERTY(PositionManager *    positionManager         READ    positionManager         CONSTANT)
    Q_PROPERTY(ViewSetup *          viewSetup               READ    viewSetup               CONSTANT)

    SettingsManager *     settingManager    ()  { return _settingsManager; }
    MapEngineManager *    mapEngineManager  ()  { return _mapEngineManager; }
    ViewPluginManager *   viewPluginManager ()  { return _viewPluginManager;}
    PositionManager *     positionManager   ()  { return _positionManager;}
    ViewSetup  *          viewSetup         ()  { return _viewSetup;}

private:
    ModuleBox *          _moduleBox;
    SettingsManager*     _settingsManager;
    MapEngineManager *   _mapEngineManager;
    ViewPluginManager *  _viewPluginManager;
    ViewSetup *          _viewSetup;
    PositionManager *    _positionManager;

};

#endif // FREEKQMLGLOBAL_H
