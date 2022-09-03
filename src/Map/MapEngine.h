#ifndef MAPENGINE_H
#define MAPENGINE_H

#include <QObject>
class FreeKUrlFactory;
///
/// \brief The MapEngine class
///地图引擎(最先初始化)
///
class MapEngine : public QObject
{
    Q_OBJECT
public:
    MapEngine(QObject *parent = nullptr);
    ~MapEngine();

    QStringList MapNameList();
    FreeKUrlFactory * freeKUrlFactory(){return _freeKUrlFactory;}

private:
    FreeKUrlFactory *    _freeKUrlFactory;

};

//全局
extern MapEngine*  getMapEngine();

#endif // MAPENGINE_H
