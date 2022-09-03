#ifndef MAPENGINEMANAGER_H
#define MAPENGINEMANAGER_H

#include <QObject>
#include "ModuleBox.h"
class FreeKApplication;
///
/// \brief The MapEngineManager class
///地图引擎管理器
///
class MapEngineManager : public Module
{
    Q_OBJECT
public:
   //
   MapEngineManager(FreeKApplication *app , ModuleBox  * moduleBox);

   void  setModuleBox(ModuleBox  * moduleBox)override ;
   Q_PROPERTY(QStringList          mapList         READ    mapList         CONSTANT)
   Q_PROPERTY(QStringList          mapProviderList READ    mapProviderList CONSTANT)

   QStringList mapList();
   QStringList mapProviderList();
   QStringList mapTypeList(QString provider);

private:
    ModuleBox *          _moduleBox;

signals:

};

#endif // MAPENGINEMANAGER_H
