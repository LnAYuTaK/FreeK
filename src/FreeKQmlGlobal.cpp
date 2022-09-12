#include "FreeKQmlGlobal.h"
#include "FreekApplication.h"
#include "SettingsManager.h"
#include "MapEngineManager.h"
#include "ViewPluginManager.h"
#include "PositionManager.h"
#include "ViewSetup.h"

FreeKQmlGlobal::FreeKQmlGlobal(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
    ,_settingsManager(nullptr)
    ,_mapEngineManager(nullptr)
    ,_viewPluginManager(nullptr)
    ,_viewSetup(nullptr)
    ,_positionManager(nullptr)
{

}
//-----------------------------------------------------------------------------
void
FreeKQmlGlobal::setModuleBox(ModuleBox  *moduleBox)
{
   QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
   _moduleBox = moduleBox;
   _settingsManager   = FreeKApp()->moduleBox()->settingsManager();
   _mapEngineManager  = FreeKApp()->moduleBox()->mapEngineManager();
   _viewPluginManager = FreeKApp()->moduleBox()->viewPluginManager();
   _viewSetup         = FreeKApp()->moduleBox()->viewSetup();
   _positionManager   = FreeKApp()->moduleBox()->positionManager();

}
