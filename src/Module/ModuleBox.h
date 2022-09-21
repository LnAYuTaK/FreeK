#ifndef MODULEBOX_H
#define MODULEBOX_H

#include <QObject>
#include "FreekApplication.h"
#include "ModuleBox.h"
class FreeKApplication;
class Module;
class ViewPluginManager;
class ViewSetup;
class SettingsManager;
class PositionManager;
class MapEngineManager;
class LinkManager;
class ProtocolManager;
///
/// \brief The ModuleBox class
/// 统一接口管理所有插件
///
class ModuleBox : public QObject
{
    Q_OBJECT
public:
    ModuleBox(FreeKApplication * app);
    void setChildBoxes(void);

    SettingsManager *     settingsManager()   { return this->_settingsManager; }
    MapEngineManager *    mapEngineManager()  { return this->_mapEngineManager; }
    ViewPluginManager *   viewPluginManager() { return this->_viewPluginManager; }
    PositionManager *     positionManager()   { return this->_positionManager; }
    ViewSetup *           viewSetup()         { return this->_viewSetup; }
    LinkManager *         linkManager()       { return this->_linkManager; }
    ProtocolManager *     protocolManager()   { return this->_protocolManager;}
private:
    SettingsManager *     _settingsManager    = nullptr;
    LinkManager *         _linkManager        = nullptr;
    MapEngineManager *    _mapEngineManager   = nullptr;
    ViewPluginManager *   _viewPluginManager  = nullptr;
    ViewSetup *           _viewSetup          = nullptr;
    PositionManager *     _positionManager    = nullptr;
    ProtocolManager *     _protocolManager    = nullptr;
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
