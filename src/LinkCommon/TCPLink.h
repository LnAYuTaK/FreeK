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
/// TcpLink
///
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

    Q_INVOKABLE void disconnect        () override{};
    Q_INVOKABLE bool connect           () override;

    inline bool isConnected            () const override{return _socketIsConnected;}
    inline TCPLinkConfig * tcpConfig   () {return this->_tcpConfig;}

private slots:
    void _readBytes   ();
    void _writeBytes  (const QByteArray data)override;
    void _socketError (QAbstractSocket::SocketError socketError);

private:

    QTcpSocket *    _socket;
    TCPLinkConfig * _tcpConfig;
    bool _socketIsConnected;

};

#endif // TCPLINK_H
