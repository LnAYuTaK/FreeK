#include "FreeKQmlGlobal.h"
#include "FreekApplication.h"

FreeKQmlGlobal::FreeKQmlGlobal(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}

//-----------------------------------------------------------------------------

void
FreeKQmlGlobal::setModuleBox(ModuleBox  *moduleBox)
{
    _moduleBox = moduleBox;
//    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);

}
