#include "FreekApplication.h"
#include "PositionManager.h"

PositionManager::PositionManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
    ,_updateInterval(100)
    ,_gcsPosition(0,0)
    ,_gcsHeading(0)
    ,_currentSource(nullptr)
    ,_defaultSource(nullptr)
{

   _currentSource   = QGeoPositionInfoSource::createDefaultSource(this);
   _currentSource->setUpdateInterval(_updateInterval);
   _currentSource->setPreferredPositioningMethods(QGeoPositionInfoSource::NonSatellitePositioningMethods);
   connect (_currentSource,&QGeoPositionInfoSource::positionUpdated,this,&PositionManager::_positionUpdated);
}

void PositionManager::setModuleBox (ModuleBox  * moduleBox)
{
     _moduleBox = moduleBox;
}
//更新当前坐标
void PositionManager::_positionUpdated(const QGeoPositionInfo &update)
{
    _geoPositionInfo = update;
    QGeoCoordinate newGCSPosition = QGeoCoordinate();
    newGCSPosition = update.coordinate();
    if (newGCSPosition != _gcsPosition) {
        _gcsPosition = newGCSPosition;
        emit gcsPositionChanged(_gcsPosition);
    }
}






