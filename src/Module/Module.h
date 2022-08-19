#ifndef MODULE_H
#define MODULE_H

#include <QObject>


//所有应用层模块的基类
class Module : public QObject
{
    Q_OBJECT
public:
    explicit Module(QObject *parent = nullptr);

private:
    static QString moduleName;

signals:

};

#endif // MODULE_H
