#ifndef POSITIONMANAGER_H
#define POSITIONMANAGER_H

#include <QObject>
#include "ModuleBox.h"

#include <QGeoPositionInfoSource>
#include <QNmeaPositionInfoSource>
class FreeKApplication;
///
/// \brief The PositonManager class
///位置管理器  //可以获取地面站位置
class PositionManager : public Module
{
     Q_OBJECT
public:
    PositionManager(FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;
    enum PositionSource{
        Simulated,
        InternalGPS,
        Log,
        NmeaGPS
    };
    Q_ENUM(PositionSource)

    Q_PROPERTY(QGeoCoordinate gcsPosition  READ gcsPosition  NOTIFY gcsPositionChanged)
    Q_PROPERTY(double         gcsHeading   READ gcsHeading   NOTIFY gcsHeadingChanged)

    Q_INVOKABLE QGeoCoordinate      gcsPosition         (void) { return _gcsPosition;}
    Q_INVOKABLE int                 gcsHeading          (void) { return _gcsHeading;}

signals:
    void gcsPositionChanged(QGeoCoordinate gcsPosition);
    void gcsHeadingChanged(int gcsHeading);

private slots:
    //更新位置
    void _positionUpdated(const QGeoPositionInfo &update);

private:
    int                         _updateInterval;
    double                      _gcsHeading;
    QGeoPositionInfo            _geoPositionInfo;
    QGeoCoordinate              _gcsPosition;
    QGeoPositionInfoSource*     _currentSource;
    QGeoPositionInfoSource*     _defaultSource;


};

#endif // POSITIONMANAGER_H
