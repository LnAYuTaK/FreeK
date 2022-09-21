#include "LinkManager.h"
#include "FreekApplication.h"
#include "MavLinkProtocol.h"
#include "TCPLink.h"
#include <QThread>
#include "SerialLink.h"
#include <QSharedPointer>
#define MAVLINKPROTOCOL
LinkManager::LinkManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
    , _protocolManager(nullptr)
{

}
//--------------------------------------------------------
void
LinkManager::setModuleBox (ModuleBox  * moduleBox)
{
    _moduleBox       = moduleBox;
    _protocolManager = FreeKApp()->moduleBox()->protocolManager();
    //Example
    QString path = "hello";
    LinkConfigPtr ptr =this->_createLinkConf(path,LinkConfig::TCPLinkType);
    _createLink(ptr);
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
        link = QSharedPointer<TCPLink>(new TCPLink(conf));
        break;
    case LinkConfig::SerialLinkType:
        link = QSharedPointer<SerialLink>(new SerialLink(conf));
        break;
//    case LinkConfig::UDPLinkType:
//        break;
//    case LinkConfig::BlueToothLinkType:
//        break;
//    case LinkConfig::ModuleBusLinkType
//        break

    default:
        return false;
    }
    _LinkInterfaceList.append(link);
    //Connect MavLinkProtocol Slots
    if(!(link.data()->connect())) {
        //HandleError
    }
    qDebug()<<QThread::currentThreadId()<<"Main";
    QThread* linkThread = new QThread(this);
    link->moveToThread(linkThread);
    linkThread->start();
//暂时先实现MAVLINK
#if defined(MAVLINKPROTOCOL)
   // connect(link.data(),&LinkInterface::bytesSend,_mavLinkProtocol,&MavLinkProtocol::mavReceivedBytes);
  //  connect(link.data(),&LinkInterface::bytesReceived,_mavLinkProtocol,&MavLinkProtocol::mavSendBytes);

#endif
    return true;
}
//--------------------------------------------------------






