#ifndef MODULEBOX_H
#define MODULEBOX_H

#include <QObject>
#include <QDebug>
class FreeKApplication;
class Module;
class MapManager;
class ViewPluginManager;

//统一接口管理所有插件
class ModuleBox : public QObject
{
    Q_OBJECT
public:
    ModuleBox(FreeKApplication * app);
    void setChildBoxes(void);

#if !defined(NOTUSEDMAP)
    MapManager *         mapManager()        {this->_mapManager;}
#endif
    ViewPluginManager *  viewPiuginManager() {this->_viewPiuginManager;}
private:
#if !defined(NOTUSEDMAP)
    MapManager *          _mapManager        =nullptr;
#endif
    ViewPluginManager *   _viewPiuginManager =nullptr;


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
