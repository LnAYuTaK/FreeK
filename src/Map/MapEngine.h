#ifndef MAPENGINE_H
#define MAPENGINE_H

#include <QObject>
///
/// \brief The MapEngine class
///地图引擎
class MapEngine : public QObject
{
    Q_OBJECT
public:
    MapEngine(QObject *parent = nullptr);

signals:

};

#endif // MAPENGINE_H
