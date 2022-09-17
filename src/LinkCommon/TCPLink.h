#ifndef TCPLINK_H
#define TCPLINK_H

#include <QObject>
#include <QTcpSocket>
#include <QMetaType>
#include <QHostAddress>

#include "LinkInterface.h"
#include "LinkConfig.h"
///
/// \brief The TCPLink class
///TcpLink
///
class LinkConfig;
class TCPLinkConfig : public LinkConfig
{
    Q_OBJECT
public:
    TCPLinkConfig(const QString &linkName);

    Q_PROPERTY(QString  host     READ host    WRITE setHost   NOTIFY hostChanged)
    Q_PROPERTY(quint16  port     READ port    WRITE setPort   NOTIFY portChanged)

    inline QString      host         (void) const   { return _host;}
    inline quint16      port         (void) const   { return _port;}

    inline void         setHost      (QString &host){ _host = host;}
    inline void         setPort      (quint16 &port){ _port = port;}

    LinkConfig::LinkType  type()     const override{return this->_linkType;}
signals:
    void portChanged(void);
    void hostChanged(void);

private:
    QString         _host;
    quint16         _port;
    LinkConfig::LinkType  _linkType;
};

class TCPLink : public LinkInterface
{
    Q_OBJECT
public:
    TCPLink(LinkConfigPtr &conf);
    ~TCPLink();

    Q_INVOKABLE void   disconnect  (void){};

    bool isConnected    (void) const{return false;}

signals:
    void _readBytes ();
private slots:
   void _writeBytes(const QByteArray data);
   void _socketError   (QAbstractSocket::SocketError socketError);


private:
    //Needs to be implemented
   bool _connect();

   QTcpSocket *     _socket;
   TCPLinkConfig *  _tcpConfig;

};

#endif // TCPLINK_H
