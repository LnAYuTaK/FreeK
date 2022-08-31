#include "SettingsManager.h"
#include "FreekApplication.h"
#include "AppSetting.h"
SettingsManager::SettingsManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
    ,_appsetting(nullptr)
{

}

void SettingsManager::setModuleBox(ModuleBox  *moduleBox) {
   _moduleBox = moduleBox;
   QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    qmlRegisterUncreatableType<SettingsManager>("FreeK.SettingsManager", 1, 0, "SettingsManager", "Reference only");
   _appsetting = new AppSetting(this);
}
