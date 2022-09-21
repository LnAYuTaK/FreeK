#include "ProtocolManager.h"
#include "FreekApplication.h"
ProtocolManager::ProtocolManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}
//-----------------------------------------------------------------------------
void
ProtocolManager::setModuleBox(ModuleBox  *moduleBox)
{
    _moduleBox = moduleBox;
     QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}



