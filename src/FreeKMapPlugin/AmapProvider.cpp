#include "AmapProvider.h"
///高德地图
AmapProvider::AmapProvider(const QString &imageFormat, const quint32 averageSize,
                           const QGeoMapType::MapStyle mapType, QObject* parent)
    : MapProvider(QStringLiteral("https://www.amap.com/"), imageFormat, averageSize, mapType, parent)
{

}
void AmapProvider::_getSecAmapWords(int x,int y,QString &sec1,QString &sec2)
{
    sec1 = ""; // after &x=...
    sec2 = ""; // after &zoom=...
    int seclen = ((x * 3) + y) % 8;
    sec2 = QString().left(seclen);
    if (y >= 10000 && y < 100000) {
        sec1 = "&s=";
    }
}
//道路地图
QString AmapProviderRoadMapProvider::_getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) {
    Q_UNUSED(networkManager)
    QString sec1    = ""; // after &x=...
    QString sec2    = ""; // after &zoom=...
    AmapProvider::_getSecAmapWords(x, y, sec1, sec2);
    return QString("http://wprd03.is.autonavi.com/appmaptile?style=7&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
}
//卫星地图
QString AmapProviderSatalliteMapProvider::_getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) {
    Q_UNUSED(networkManager)
    QString sec1    = ""; // after &x=...
    QString sec2    = ""; // after &zoom=...
    AmapProvider::_getSecAmapWords(x, y, sec1, sec2);

    return QString("http://wprd03.is.autonavi.com/appmaptile?lang=zh_cn&size=1&style=7&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
}
//地形图
QString AmapProviderTerrainMapProvider::_getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) {
    Q_UNUSED(networkManager)
    QString sec1    = ""; // after &x=...
    QString sec2    = ""; // after &zoom=...
    AmapProvider::_getSecAmapWords(x, y, sec1, sec2);
    return QString("http://wprd03.is.autonavi.com/appmaptile?lang=zh_cn&size=1&style=6&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
}
//混合地图
QString AmapProviderHybridMapProvider::_getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) {
    Q_UNUSED(networkManager)
    QString sec1    = ""; // after &x=...
    QString sec2    = ""; // after &zoom=...
    AmapProvider::_getSecAmapWords(x, y, sec1, sec2);
    return QString("http://wprd03.is.autonavi.com/appmaptile?lang=zh_cn&size=1&style=8&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
}














