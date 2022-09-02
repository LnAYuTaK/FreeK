#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include "ModuleBox.h"
class FreeKApplication;
class AppSetting;
/// 用于系统设置文件夹路径配置各个模块的参数
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
