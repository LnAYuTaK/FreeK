#include "FreeKUrlFactory.h"

#include "MapProvider.h"
#include "AmapProvider.h"
//-----------------------------------------------------------------------------
///
/// \brief FreeKUrlFactory::FreeKUrlFactory
/// \param parent
/// 这里实例化不同Provider
FreeKUrlFactory::FreeKUrlFactory() : _timeout(5 * 1000) {

   //高德地图支持
    _providersTable["Amap Street Map"] = new AmapProviderRoadMapProvider(this);
    _providersTable["Amap Satellite"]  = new AmapProviderSatalliteMapProvider(this);
    _providersTable["Amap Terrain"]    = new AmapProviderTerrainMapProvider(this);
    _providersTable["Amap Hybrid"]    = new AmapProviderHybridMapProvider(this);
}

void FreeKUrlFactory::registerProvider(QString name, MapProvider* provider) {
    _providersTable[name] = provider;
}

//-----------------------------------------------------------------------------
FreeKUrlFactory::~FreeKUrlFactory() {

}

QString FreeKUrlFactory::getImageFormat(int id, const QByteArray& image) {
    QString type = getTypeFromId(id);
    if (_providersTable.find(type) != _providersTable.end()) {
        return _providersTable[getTypeFromId(id)]->getImageFormat(image);
    } else {
        qDebug() << "getImage : Map not registered " << type;
        return "";
    }
}
//-----------------------------------------------------------------------------
QString FreeKUrlFactory::getImageFormat(QString type, const QByteArray& image) {
    if (_providersTable.find(type) != _providersTable.end()) {
        return _providersTable[type]->getImageFormat(image);
    } else {
         qDebug()<< "getImageFormat : Map not registered :" << type;
        return "";
    }
}
//-----------------------------------------------------------------------------
QNetworkRequest FreeKUrlFactory::getTileURL(int id, int x, int y, int zoom,
                                       QNetworkAccessManager* networkManager) {

    QString type = getTypeFromId(id);
    if (_providersTable.find(type) != _providersTable.end()) {
        return _providersTable[type]->getTileURL(x, y, zoom, networkManager);
    }

    qDebug() << "getTileURL : map not registered :" << type;
    return QNetworkRequest(QUrl());
}

//-----------------------------------------------------------------------------
QNetworkRequest FreeKUrlFactory::getTileURL(QString type, int x, int y, int zoom,
                                       QNetworkAccessManager* networkManager) {
    if (_providersTable.find(type) != _providersTable.end()) {
        return _providersTable[type]->getTileURL(x, y, zoom, networkManager);
    }
    qDebug() << "getTileURL : map not registered :" << type;
    return QNetworkRequest(QUrl());
}

//-----------------------------------------------------------------------------
quint32 FreeKUrlFactory::averageSizeForType(QString type) {
    if (_providersTable.find(type) != _providersTable.end()) {
        return _providersTable[type]->getAverageSize();
    }
    qDebug() << "UrlFactory::averageSizeForType " << type<< " Not registered";
    return AVERAGE_TILE_SIZE;
}
//-----------------------------------------------------------------------------
QString FreeKUrlFactory::getTypeFromId(int id) {

    QHashIterator<QString, MapProvider*> i(_providersTable);

    while (i.hasNext()) {
        i.next();
        if ((int)(qHash(i.key())>>1) == id) {
            return i.key();
        }
    }
    qDebug() << "getTypeFromId : id not found" << id;
    return "";
}
//-----------------------------------------------------------------------------
MapProvider* FreeKUrlFactory::getMapProviderFromId(int id)
{
    QString type = getTypeFromId(id);
    if (!type.isEmpty()) {
        if (_providersTable.find(type) != _providersTable.end()) {
            return _providersTable[type];
        }
    }
    return nullptr;
}
//-----------------------------------------------------------------------------
int FreeKUrlFactory::getIdFromType(QString type) {
    return (int)(qHash(type)>>1);
}
//-----------------------------------------------------------------------------
int
FreeKUrlFactory::long2tileX(QString mapType, double lon, int z)
{
    return _providersTable[mapType]->long2tileX(lon, z);
}

//-----------------------------------------------------------------------------
int
FreeKUrlFactory::lat2tileY(QString mapType, double lat, int z)
{
    return _providersTable[mapType]->lat2tileY(lat, z);
}

//-----------------------------------------------------------------------------

