#include "MapEngine.h"
#include "FreeKMapPlugin/FreeKUrlFactory.h"

#include <QFile>
#include <QTextStream>
static MapEngine* FreeKMapEngine=nullptr;
MapEngine::MapEngine(QObject *parent)
    : QObject{parent}
{
     _freeKUrlFactory = new FreeKUrlFactory();
}

//-----------------------------------------------------------------------------

MapEngine::
~MapEngine()
{
    _freeKUrlFactory->deleteLater();
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
QStringList
MapEngine::MapNameList()
{
    return QStringList(getMapEngine()->freeKUrlFactory()->getProviderTable().keys());
}

//-----------------------------------------------------------------------------
//单例接口全局
MapEngine *
getMapEngine()
{
    if(!FreeKMapEngine)
        FreeKMapEngine = new MapEngine();
    return FreeKMapEngine;
}
//-----------------------------------------------------------------------------

