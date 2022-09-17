#include "TCPLink.h"
#include <QHostInfo>
#include <QSignalSpy>
#define DefaultHost "192.168.31.113"
#define DefaultPort 8900
TCPLinkConfig::TCPLinkConfig(const QString &LinkName)
    :LinkConfig(LinkName)
    ,_host(DefaultHost)
    ,_port(DefaultPort)
    ,_linkType(TCPLinkType)
{

}
//----------------------------------------------
TCPLink::TCPLink(LinkConfigPtr &conf)
    : LinkInterface(conf)
    ,_socket(nullptr)
    ,_tcpConfig(qobject_cast<TCPLinkConfig *>(conf.data()))
{

}

TCPLink::~TCPLink()
{

}
//----------------------------------------------
void
TCPLink::_writeBytes(const QByteArray data)
{
//   _socket.connectToHost(_tcpConfig->host(),_tcpConfig->port());
//   if(_socket.waitForReadyRead(5)){
//       _socket.write(data);
//   }
}
//----------------------------------------------
bool
TCPLink::_connect()
{
    Q_ASSERT(_socket == nullptr);
    _socket = new QTcpSocket();
    QObject::connect(_socket, &QIODevice::readyRead, this, &TCPLink::_readBytes);

    QSignalSpy errorSpy(_socket, &QAbstractSocket::errorOccurred);
    QObject::connect(_socket, &QAbstractSocket::errorOccurred, this, &TCPLink::_socketError);

    _socket->connectToHost(_tcpConfig->host(), _tcpConfig->port());

    if (!_socket->waitForConnected(1000))
    {
        if (errorSpy.count() == 0) {
            //
            //emit communicationError(tr("Link Error"), tr("Error on link %1. Connection failed").arg(_config->name()));
        }
        _socket->deleteLater();
        _socket = nullptr;
        return false;
    }
    //_socketIsConnected = true;
    //emit connected();
    return true;
}
//----------------------------------------------
void TCPLink::_socketError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    //emit communicationError(tr("Link Error"), tr("Error on link %1. Error on socket: %2.").arg(_config->name()).arg(_socket->errorString()));
}
