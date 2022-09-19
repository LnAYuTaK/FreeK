#include "LinkManager.h"
#include "FreekApplication.h"
#include "MavLinkProtocol.h"
#include "TCPLink.h"
#include <QThread>
LinkManager::LinkManager(FreeKApplication *app , ModuleBox  * moduleBox)
    :Module(app,moduleBox)
    , _mavLinkProtocol(nullptr)
{

}
//--------------------------------------------------------
void
LinkManager::setModuleBox (ModuleBox  * moduleBox)
{
    _moduleBox       = moduleBox;
    _mavLinkProtocol = FreeKApp()->moduleBox()->mavLinkProtocol();
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
        link =QSharedPointer<TCPLink>(new TCPLink(conf));
        qDebug() <<qobject_cast<TCPLink *>(link.data())->tcpConfig()->type();
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
    //Connect MavLinkProtocol Slots
    if(!(link.data()->connect())) {
        //HandleError
    }
    qDebug()<<QThread::currentThreadId()<<"Main";
    QThread* thread = new QThread(this);
    link->moveToThread(thread);
    thread->start();
    connect(link.data(),&LinkInterface::bytesSend,_mavLinkProtocol,&MavLinkProtocol::mavReceivedBytes);
    connect(link.data(),&LinkInterface::bytesReceived,_mavLinkProtocol,&MavLinkProtocol::mavSendBytes);
    return true;
}
//--------------------------------------------------------






