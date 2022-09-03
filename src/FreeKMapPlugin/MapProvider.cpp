#include "MapProvider.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
MapProvider::MapProvider(const QString &referrer, const QString &imageFormat,
                         const quint32 averageSize, const QGeoMapType::MapStyle mapType, QObject* parent)
    : QObject(parent)
    , _referrer(referrer)
    , _imageFormat(imageFormat)
    , _averageSize(averageSize)
    , _mapType(mapType)
{
    const QStringList langs = QLocale::system().uiLanguages();
    if (langs.length() > 0) {
        _language = langs[0];
    }
}

QNetworkRequest MapProvider::getTileURL(const int x, const int y, const int zoom, QNetworkAccessManager* networkManager) {
    //-- Build URL
    QNetworkRequest request;
    const QString url = _getURL(x, y, zoom, networkManager);
    if (url.isEmpty()) {
        return request;
    }
    request.setUrl(QUrl(url));
    request.setRawHeader(QByteArrayLiteral("Accept"), QByteArrayLiteral("*/*"));
    request.setRawHeader(QByteArrayLiteral("Referrer"), _referrer.toUtf8());
    request.setRawHeader(QByteArrayLiteral("User-Agent"), _userAgent);
    return request;
}

QString MapProvider::getImageFormat(const QByteArray& image) const {
    QString format;
    if (image.size() > 2) {
        if (image.startsWith(reinterpret_cast<const char*>(pngSignature)))
            format = QStringLiteral("png");
        else if (image.startsWith(reinterpret_cast<const char*>(jpegSignature)))
            format = QStringLiteral("jpg");
        else if (image.startsWith(reinterpret_cast<const char*>(gifSignature)))
            format = QStringLiteral("gif");
        else {
            return _imageFormat;
        }
    }
    return format;
}

QString MapProvider::_tileXYToQuadKey(const int tileX, const int tileY, const int levelOfDetail) const {
    QString quadKey;
    for (int i = levelOfDetail; i > 0; i--) {
        char digit = '0';
        const int  mask  = 1 << (i - 1);
        if ((tileX & mask) != 0) {
            digit++;
        }
        if ((tileY & mask) != 0) {
            digit++;
            digit++;
        }
        quadKey.append(digit);
    }
    return quadKey;
}

int MapProvider::_getServerNum(const int x, const int y, const int max) const {
    return (x + 2 * y) % max;
}

int MapProvider::long2tileX(const double lon, const int z) const {
    return static_cast<int>(floor((lon + 180.0) / 360.0 * pow(2.0, z)));
}

//-----------------------------------------------------------------------------
int MapProvider::lat2tileY(const double lat, const int z) const {
    return static_cast<int>(floor(
        (1.0 -
         log(tan(lat * M_PI / 180.0) + 1.0 / cos(lat * M_PI / 180.0)) / M_PI) /
        2.0 * pow(2.0, z)));
}

