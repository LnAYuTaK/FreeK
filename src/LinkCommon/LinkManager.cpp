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
}
//--------------------------------------------------------
LinkConfigPtr
LinkManager::_createLinkConf(QString &linkName ,int type)
{
    LinkConfig  *conf =nullptr;
    switch(type){
        case LinkConfig::TCPLinkType:
            conf = new TCPLinkConfig(linkName);
            break;
    }
    _LinkConfigList.append(LinkConfigPtr(conf));
    return _LinkConfigList.last();
}
//--------------------------------------------------------
bool
LinkManager::_createLink(LinkConfigPtr conf)
{
   LinkInterfacePtr link = nullptr;
    switch (conf->type()) {
    case LinkConfig::TCPLinkType:
        link =QSharedPointer<TCPLink>(new TCPLink(conf));
        break;
//    case LinkConfig::SerialLinkType:
//        break;
//    case LinkConfig::UDPLinkType:
//        break;
//    case LinkConfig::BlueToothLinkType:
//        break;
    default:
        return false;
    }
    _LinkInterfaceList.append(link);
    return true;
}
//--------------------------------------------------------






