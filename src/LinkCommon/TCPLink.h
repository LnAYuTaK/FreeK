#ifndef TCPLINK_H
#define TCPLINK_H

#include <QObject>
#include "LinkInterface.h"
#include "LinkConfig.h"
#include <QTcpSocket>
///
/// \brief The TCPLink class
///TcpLink
///
class TCPLinkConfig : public LinkConfig
{
    Q_OBJECT
public:
    TCPLinkConfig(QString &linkName,LinkConfig::LinkType type = TCPLink);

    Q_PROPERTY(QString  host     READ host    WRITE setHost   NOTIFY hostChanged)
    Q_PROPERTY(quint16  port     READ port    WRITE setPort   NOTIFY portChanged)

    inline QString      host         (void) const   { return _host;}
    inline quint16      port         (void) const   { return _port;}

    inline void         setHost      (QString &host){ _host = host;}
    inline void         setPort      (quint16 &port){ _port = port;}

signals:
    void portChanged(void);
    void hostChanged(void);

private:
    QString         _host;
    quint16         _port;
};

class TCPLink : public LinkInterface
{
    Q_OBJECT
public:
    TCPLink(TCPLinkConfig &conf);
    ~TCPLink();

    Q_INVOKABLE void   disconnect  (void){};

    bool isConnected    (void) const{return false;}
private slots:
   void _writeBytes(const QByteArray data);

private:
    //Needs to be implemented
   bool _connect();

   QTcpSocket      _socket;
   TCPLinkConfig*  _config;

};

#endif // TCPLINK_H
