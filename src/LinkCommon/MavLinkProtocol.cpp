#include "MavLinkProtocol.h"
#include "LinkInterface.h"

MavLinkProtocol::MavLinkProtocol()
{

}
//-----------------------------------------------------------------------------
void
MavLinkProtocol::mavReceivedBytes(LinkInterface* link, QByteArray data)
{
    qDebug() << data ;
}
//-----------------------------------------------------------------------------
void
MavLinkProtocol::mavSendBytes(LinkInterface* link, QByteArray data)
{
    qDebug()<<QThread::currentThreadId()<<"Protocol";
    qDebug() << data ;
}
