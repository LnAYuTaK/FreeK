#ifndef MAPTASKWORKER_H
#define MAPTASKWORKER_H

#include <QObject>

/// \brief The MapTaskWorker class
/// MapTask的 执行者 用于执行不同类型的Task
/// 处理与数据库相关的一些地图缓存业务
class MapTaskWorker : public QObject
{
    Q_OBJECT
public:
    explicit MapTaskWorker(QObject *parent = nullptr);

signals:

};



#endif // MAPTASKWORKER_H
