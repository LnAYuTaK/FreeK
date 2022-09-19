#ifndef LINKINTERFACE_H
#define LINKINTERFACE_H

#include <QDateTime>
#include <QLoggingCategory>
#include <QMutex>
#include <QMutexLocker>
#include <QMetaType>
#include <QSharedPointer>
#include <QDebug>
#include <QTimer>
#include <memory>
#include <QObject>
#include "LinkConfig.h"
class LinkConfig;
///
/// \brief The LinkInterface class
/// 连接接口的基类
class LinkInterface : public QObject
{
    Q_OBJECT
public:
    virtual ~LinkInterface();
    //Needs to be implemented
    Q_INVOKABLE virtual bool connect (void) = 0;
    //Needs to be implemented
    Q_INVOKABLE virtual void  disconnect (void) = 0;
    //Needs to be implemented
    virtual bool isConnected    (void) const = 0;

signals:
    void connected          (void);
    void disconnected       (void);
    void bytesReceived      (LinkInterface* link, QByteArray data);
    void bytesSend          (LinkInterface* link, QByteArray data);
    void communicationError (const QString& title, const QString& error);


protected:
    LinkInterface(LinkConfigPtr& config);

private: 
    LinkConfigPtr _conf;

private slots:
    //Needs to be implemented
    virtual void _writeBytes    (const QByteArray) = 0;

};

#endif //LINKINTERFACE_H


