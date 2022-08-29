#include "AppMsgManager.h"

AppMsgManager::AppMsgManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}

void AppMsgManager::setModuleBox(ModuleBox  *moduleBox)
{
   _moduleBox = moduleBox;
}

