#ifndef MODULEBOX_H
#define MODULEBOX_H

#include <QObject>
#include "FreekApplication.h"
class FreeKApplication;
class Module;
class MapManager;
class ViewPluginManager;
class ViewSetup;
//统一接口管理所有插件
class ModuleBox : public QObject
{
    Q_OBJECT
public:
    ModuleBox(FreeKApplication * app);
    void setChildBoxes(void);

#if !defined(NOTUSEDMAP)
    MapManager *         mapManager()        {return this->_mapManager;}
#endif
    ViewPluginManager *  viewPiuginManager() {return this->_viewPiuginManager;}
private:
#if !defined(NOTUSEDMAP)
    MapManager *          _mapManager        =nullptr;
#endif
    ViewPluginManager *   _viewPiuginManager =nullptr;

    ViewSetup *           _viewSetup         =nullptr;




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
