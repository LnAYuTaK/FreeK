#include "TCPLink.h"
#include "LinkConfig.h"

#define DefaultHost "192.168.31.113"
#define DefaultPort 8900
TCPLinkConfig::TCPLinkConfig(QString &LinkName,LinkConfig::LinkType)
    :LinkConfig(LinkName,TCPLink)
    ,_host(DefaultHost)
    ,_port(DefaultPort)
{

}
//----------------------------------------------
TCPLink::TCPLink(TCPLinkConfig &conf)
    : LinkInterface(conf)
    ,_socket(nullptr)
    ,_config(&conf)

{

}

TCPLink::~TCPLink()
{

}
//----------------------------------------------
void
TCPLink::_writeBytes(const QByteArray data)
{



}
//----------------------------------------------
bool
TCPLink::_connect()
{

 return false;
}
//----------------------------------------------
