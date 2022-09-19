#include "MavLinkProtocol.h"
#include "FreekApplication.h"
#include "LinkInterface.h"
MavLinkProtocol::MavLinkProtocol(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}
//-----------------------------------------------------------------------------
void
MavLinkProtocol::setModuleBox (ModuleBox  * moduleBox)
{
     _moduleBox = moduleBox;
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

qDebug() << data ;

}
