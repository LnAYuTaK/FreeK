#include "ViewSetup.h"
#include "FreekApplication.h"
ViewSetup::ViewSetup(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}

void ViewSetup::setModuleBox(ModuleBox  *moduleBox) {
   _moduleBox = moduleBox;
}




