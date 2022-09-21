#include "MapEngineManager.h"
#include "MapEngine.h"
#include "FreekApplication.h"
#include <QRegularExpression>
MapEngineManager::MapEngineManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}
//-----------------------------------------------------------------------------
void
MapEngineManager::setModuleBox(ModuleBox  *moduleBox)
{
    _moduleBox = moduleBox;
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);

}
//-----------------------------------------------------------------------------
QStringList
MapEngineManager::mapList()
{
    return getMapEngine()->MapNameList();
}

//-----------------------------------------------------------------------------
QStringList
MapEngineManager::mapProviderList()
{
    QStringList mapList = getMapEngine()->MapNameList();
    mapList.replaceInStrings(QRegExp("^([^\\ ]*) (.*)$"),"\\1");
    mapList.removeDuplicates();
    return mapList;
}

//-----------------------------------------------------------------------------
QStringList
MapEngineManager::mapTypeList(QString provider)
{
    QStringList mapList = getMapEngine()->MapNameList();
    mapList = mapList.filter(QRegularExpression(provider));
    mapList.replaceInStrings(QRegExp("^([^\\ ]*) (.*)$"),"\\2");
    mapList.removeDuplicates();
    return mapList;
}
//-----------------------------------------------------------------------------


