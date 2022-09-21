#ifndef APPMSGMANAGER_H
#define APPMSGMANAGER_H

#include <QObject>
#include "ModuleBox.h"
///
/// \brief 软件提示信息报错提示等
///
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
