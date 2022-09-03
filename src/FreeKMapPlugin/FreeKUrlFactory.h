#ifndef FREEKURLFACTORY_H
#define FREEKURLFACTORY_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
class MapProvider;
///
/// \brief The FreeKUrlFactory class
///创建所有URLProvider:
class FreeKUrlFactory : public QObject
{
    Q_OBJECT
public:
    FreeKUrlFactory();
    ~FreeKUrlFactory();
    QNetworkRequest getTileURL          (QString type, int x, int y, int zoom, QNetworkAccessManager* networkManager);
    QNetworkRequest getTileURL          (int id, int x, int y, int zoom, QNetworkAccessManager* networkManager);

    QString         getImageFormat      (QString type, const QByteArray& image);
    QString         getImageFormat      (int id , const QByteArray& image);

    quint32  averageSizeForType  (QString type);

    int long2tileX(QString mapType, double lon, int z);
    int lat2tileY(QString mapType, double lat, int z);

    QHash<QString, MapProvider*> getProviderTable(){return _providersTable;}

    int getIdFromType(QString type);
    QString getTypeFromId(int id);
    MapProvider* getMapProviderFromId(int id);

    bool isElevation(int mapId);

  private:
    int             _timeout;
    QHash<QString, MapProvider*> _providersTable;
    void registerProvider(QString Name, MapProvider* provider);

signals:

};

#endif // FREEKURLFACTORY_H
