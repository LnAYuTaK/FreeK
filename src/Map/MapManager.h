#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <QObject>
#include "ModuleBox.h"
class FreeKApplication;
class MapManager : public Module
{
    Q_OBJECT
public:
   explicit MapManager(FreeKApplication *app , ModuleBox  * moduleBox);

   void  setModuleBox(ModuleBox  * moduleBox)override ;
private:
    ModuleBox *  _moduleBox;
};

#endif // MAPMANAGER_H
