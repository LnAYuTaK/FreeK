#ifndef VIEWSETUP_H
#define VIEWSETUP_H

#include <QObject>
#include "ModuleBox.h"
class  FreeKApplication;
class ViewSetup : public Module
{
    Q_OBJECT
public:
    ViewSetup(FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;

private:








};

#endif // VIEWSETUP_H
