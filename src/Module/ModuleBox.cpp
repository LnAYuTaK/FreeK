#include "ModuleBox.h"
#include "ViewPluginManager.h"
#include "MapManager.h"
#include "FreekApplication.h"
#include "ViewSetup.h"
#include "ScreenTool.h"
#include "SettingsManager.h"
ModuleBox::ModuleBox(FreeKApplication * app)
{
  //初始化所有模块
  //_logModule  = new   Module     (app,this);

    _settingsManager  =new    SettingsManager   (app,this);
#if !defined(NOTUSEDMAP)
    _mapManager       = new   MapManager        (app,this);
#endif
    _viewPiuginManager = new   ViewPluginManager (app,this);
    _viewSetup         = new   ViewSetup         (app,this);
}
//
void ModuleBox::setChildBoxes(void)
{

    _settingsManager->setModuleBox(this);
#if !defined(NOTUSEDMAP)
    _mapManager->setModuleBox(this);
#endif
    _viewPiuginManager->setModuleBox(this);
    _viewSetup->setModuleBox(this);
}

Module::Module(FreeKApplication * app,ModuleBox *moduleBox)
    :QObject(moduleBox),
    _moduleBox(nullptr),
    _app(app)
{

}

void Module::setModuleBox(ModuleBox *moduleBox)
{
    _moduleBox  = moduleBox;
}


