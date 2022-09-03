#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include "ModuleBox.h"
class FreeKApplication;
class AppSetting;
///
/// \brief The AppSetting class
///配置管理器
///
class SettingsManager : public Module
{
    Q_OBJECT
public:
    SettingsManager(FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;
    Q_PROPERTY(AppSetting *appSetting    READ appSetting    CONSTANT)

    Q_INVOKABLE AppSetting * appSetting(){return _appsetting;}
private:
    AppSetting  * _appsetting;

    //MapSetting//
    //LinkSetting//

};

#endif // SETTINGSMANAGER_H
