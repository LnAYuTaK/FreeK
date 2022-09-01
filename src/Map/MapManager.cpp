#include "MapManager.h"
#include "QGeoServiceProviderPluginFreeK.h"
MapManager::MapManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}

void MapManager::setModuleBox(ModuleBox  *moduleBox)
{
    _moduleBox = moduleBox;
}




