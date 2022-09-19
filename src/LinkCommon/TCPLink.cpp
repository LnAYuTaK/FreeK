#include "TCPLink.h"
#include <QHostInfo>
#include <QSignalSpy>
#define DefaultHost "192.168.3.113"
#define DefaultPort 8080
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
    ,_socketIsConnected(false)
{

}
//----------------------------------------------
TCPLink::~TCPLink()
{

}
//----------------------------------------------
void
TCPLink::_writeBytes(const QByteArray data)
{
    if(_socket){
        _socket->write(data);
        emit bytesSend(this,data);
    }
}
//----------------------------------------------




//----------------------------------------------
void
TCPLink::_readBytes()
{

    qDebug()<<QThread::currentThreadId()<<"Main";

    if (_socket) {
        qint64 byteCount = _socket->bytesAvailable();

        if (byteCount)
        {
            QByteArray buffer;
            buffer.resize(byteCount);
            _socket->read(buffer.data(), buffer.size());
            //LinkInterface
            emit bytesReceived(this, buffer);
        }
    }
}
//----------------------------------------------
bool
TCPLink::connect()
{
    Q_ASSERT(_socket == nullptr);
    _socket = new QTcpSocket(this);
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
    _socketIsConnected = true;
    emit connected();
    return true;
}
//----------------------------------------------
void TCPLink::_socketError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    //emit communicationError(tr("Link Error"), tr("Error on link %1. Error on socket: %2.").arg(_config->name()).arg(_socket->errorString()));
}
