#ifndef MODULEBOX_H
#define MODULEBOX_H

#include <QObject>
#include "FreekApplication.h"
class FreeKApplication;
class Module;
class MapManager;
class ViewPluginManager;
class ViewSetup;
class SettingsManager;
class PositionManager;
//统一接口管理所有插件
class ModuleBox : public QObject
{
    Q_OBJECT
public:
    ModuleBox(FreeKApplication * app);
    void setChildBoxes(void);

    SettingsManager *     settingsManager()   {return this->_settingsManager;}
#if !defined(NOTUSEDMAP)
    MapManager *          mapManager()        {return this->_mapManager;}
#endif
    ViewPluginManager *   viewPiuginManager() {return this->_viewPiuginManager;}
    PositionManager *     positionManager()   {return this->_positionManager;}

private:
    SettingsManager*      _settingsManager    =nullptr;
#if !defined(NOTUSEDMAP)
    MapManager *          _mapManager         =nullptr;
#endif
    ViewPluginManager *   _viewPiuginManager  =nullptr;

    ViewSetup *           _viewSetup          =nullptr;

    PositionManager *     _positionManager   =nullptr;
    //TUDO
    void checkModuleState();

signals:
};

class Module : public QObject
{
    Q_OBJECT
public:
    Module(FreeKApplication * app,ModuleBox* moduleBox);
    virtual void setModuleBox(ModuleBox *moduleBox);
protected:
    ModuleBox  * _moduleBox;
    FreeKApplication * _app;
signals:

};

#endif // MODULEBOX_H
