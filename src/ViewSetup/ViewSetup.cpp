#include "ViewSetup.h"
#include "FreekApplication.h"
#include "ScreenTool.h"
ScreenTool * ViewSetup::_screenTool =nullptr;
ViewSetup::ViewSetup(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}

ScreenTool *ViewSetup::screenTool(QQmlEngine *, QJSEngine *) {

    if(_screenTool==nullptr) {
      _screenTool = new ScreenTool();
    }
    return _screenTool;
}

void ViewSetup::setModuleBox(ModuleBox  *moduleBox) {
   _moduleBox = moduleBox;
   //
   qmlRegisterUncreatableType<ViewSetup>("FreeK.ViewSetup", 1, 0, "ViewSetup", "Reference only");

   ///单例
   qmlRegisterSingletonType<ScreenTool> ("FreeK.ViewSetup.ScreenTool", 1, 0,"ScreenTool",screenTool);

}




