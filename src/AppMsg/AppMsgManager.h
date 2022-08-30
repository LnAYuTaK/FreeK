#ifndef APPMSGMANAGER_H
#define APPMSGMANAGER_H

#include <QObject>
#include "ModuleBox.h"
//全局消息传递
//日志log模块
class FreeKApplication;
class AppMsgManager : public Module
{
    Q_OBJECT
public:
    explicit AppMsgManager(FreeKApplication *app , ModuleBox  * moduleBox);

    void  setModuleBox(ModuleBox  * moduleBox)override ;
private:
    ModuleBox *  _moduleBox;
};

#endif // APPMSGMANAGER_H
