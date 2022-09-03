#ifndef AMAPPROVIDER_H
#define AMAPPROVIDER_H

#include "MapProvider.h"
#include <QObject>
///
/// \brief The AmapProvider class
///高德地图
///
///
static const quint32 AVERAGE_BING_STREET_MAP = 1297;
static const quint32 AVERAGE_BING_SAT_MAP    = 19597;

class AmapProvider : public MapProvider
{
    Q_OBJECT
public:
     AmapProvider(const QString &imageFormat, const quint32 averageSize,
                    const QGeoMapType::MapStyle mapType, QObject* parent = nullptr);

     ~AmapProvider()  =default;
     void _getSecAmapWords(int x,int y,QString &sec1,QString &sec2);
};

class AmapProviderRoadMapProvider : public AmapProvider {
    Q_OBJECT
public:
    AmapProviderRoadMapProvider(QObject* parent = nullptr)
        : AmapProvider(QStringLiteral("png"), AVERAGE_BING_STREET_MAP, QGeoMapType::StreetMap, parent) {}

    QString _getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) override;
};

class AmapProviderSatalliteMapProvider : public AmapProvider {
    Q_OBJECT
public:
    AmapProviderSatalliteMapProvider(QObject* parent = nullptr)
        : AmapProvider(QStringLiteral("jpg"), AVERAGE_BING_SAT_MAP, QGeoMapType::StreetMap, parent) {}

    QString _getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) override;
};

class AmapProviderTerrainMapProvider : public AmapProvider {
    Q_OBJECT
public:
    AmapProviderTerrainMapProvider(QObject* parent = nullptr)
        : AmapProvider(QStringLiteral("jpg"), AVERAGE_BING_SAT_MAP, QGeoMapType::StreetMap, parent) {}

    QString _getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) override;
};

class AmapProviderHybridMapProvider : public AmapProvider {
    Q_OBJECT
public:
  AmapProviderHybridMapProvider(QObject* parent = nullptr)
        : AmapProvider(QStringLiteral("jpg"), AVERAGE_BING_SAT_MAP, QGeoMapType::StreetMap, parent) {}

    QString _getURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) override;
};



















#endif // AMAPPROVIDER_H
