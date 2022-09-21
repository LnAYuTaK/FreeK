#include "ModuleBox.h"
#include "ViewPluginManager.h"
#include "FreekApplication.h"
#include "ViewSetup.h"
#include "SettingsManager.h"
#include "PositionManager.h"
#include "MapEngineManager.h"
#include "LinkManager.h"
#include "ProtocolManager.h"
ModuleBox::ModuleBox(FreeKApplication * app)
{
    _settingsManager   = new   SettingsManager   (app,this);
    _linkManager       = new   LinkManager       (app,this);
    _protocolManager   = new   ProtocolManager   (app,this);
    _mapEngineManager  = new   MapEngineManager  (app,this);
    _viewPluginManager = new   ViewPluginManager (app,this);
    _viewSetup         = new   ViewSetup         (app,this);
    _positionManager   = new   PositionManager   (app,this);

}

//-----------------------------------------------------------------------------
void
ModuleBox::setChildBoxes(void)
{
    _settingsManager->setModuleBox(this);
    _linkManager->setModuleBox(this);
    _mapEngineManager->setModuleBox(this);
    _viewPluginManager->setModuleBox(this);
    _viewSetup->setModuleBox(this);
    _positionManager->setModuleBox(this);
    _protocolManager->setModuleBox(this);
}

//-----------------------------------------------------------------------------
Module::
Module(FreeKApplication * app,ModuleBox *moduleBox)
    :QObject(moduleBox),
    _moduleBox(nullptr),
    _app(app)
{

}

//-----------------------------------------------------------------------------
void
Module::setModuleBox(ModuleBox *moduleBox)
{
    _moduleBox  = moduleBox;
}

//-----------------------------------------------------------------------------

