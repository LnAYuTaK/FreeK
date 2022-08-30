#ifndef VIEWSETUP_H
#define VIEWSETUP_H

#include <QObject>
#include "ModuleBox.h"
class  FreeKApplication;
///设置主视图一些显示逻辑
class ViewSetup : public Module
{
    Q_OBJECT
public:
    ViewSetup(FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;

    static ScreenTool *screenTool(QQmlEngine *, QJSEngine *);

private:
   static  ScreenTool *_screenTool;
};

#endif // VIEWSETUP_H
