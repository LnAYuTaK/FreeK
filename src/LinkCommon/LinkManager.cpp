#include "LinkManager.h"
#include "FreekApplication.h"
#include "TCPLink.h"

LinkManager::LinkManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
{

}

//--------------------------------------------------------
void
LinkManager::setModuleBox (ModuleBox  * moduleBox)
{
     _moduleBox = moduleBox;
//     QString TcpLinkName  = "TCP";
//     TCPLinkConfig *link =new TCPLinkConfig(TcpLinkName);
//     QSharedPointer<TCPLinkConfig> obj =QSharedPointer<TCPLinkConfig>(link);
}

//--------------------------------------------------------
void
createLink(LinkConfigPtr &conf)
{

   LinkInterfacePtr link = nullptr;
    switch (conf->linkType()) {
    case LinkConfig::TCPLink:

        break;
//    case LinkConfig::SerialLink:
//        break;
//    case LinkConfig::UDPLink:
//        break;
//    case LinkConfig::BlueToothLink:

//        break;
//    default:
//        return;
    }
}
//--------------------------------------------------------






