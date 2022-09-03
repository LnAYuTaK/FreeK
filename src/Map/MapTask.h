#ifndef MAPTASK_H
#define MAPTASK_H

#include <QObject>
/// \brief The MapTask class
///MapTask基类 处理各种任务
///
class MapTask : public QObject
{
    Q_OBJECT
public:
     MapTask(QObject *parent = nullptr);

     enum MapTaskType{
        TaskInit,

     };
     Q_ENUM(MapTaskType)



signals:

};







#endif // MAPTASK_H
