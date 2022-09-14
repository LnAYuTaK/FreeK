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
class LinkConfig;
class LinkInterface : public QObject
{
    Q_OBJECT
public:
    LinkInterface(LinkConfig& config);

    virtual ~LinkInterface();

    Q_INVOKABLE virtual void   disconnect  (void) = 0;

    virtual bool isConnected    (void) const = 0;
signals:
    void connected          (void);
    void bytesReceived      (LinkInterface* link, QByteArray data);
    void bytesSent          (LinkInterface* link, QByteArray data);
    void disconnected       (void);
    void communicationError (const QString& title, const QString& error);
    void _invokeWriteBytes  (QByteArray);

private slots:
    //Needs to be implemented
    virtual void _writeBytes(const QByteArray) = 0;

private:
    //Needs to be implemented
    virtual bool _connect(void) = 0;

};

#endif //LINKINTERFACE_H


