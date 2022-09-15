#ifndef LINKCONFIG_H
#define LINKCONFIG_H

#include <QObject>
class LinkInterface;
///
/// \brief The LinkConfig class
///所有连接配置的基类
class LinkConfig : public QObject
{
    Q_OBJECT
public:
    enum LinkType{
        TCPLink,
        UDPLink,
        SerialLink,
        BlueToothLink,
        DefaultLink
    };
    Q_ENUM(LinkType)

    LinkConfig(QString &linkName,LinkType linkType);

    inline QString linkName(){return this->_linkName;}
    inline void setLinkName(QString &newLinkName) { if(newLinkName!="")  _linkName =newLinkName;}

    inline LinkType linkType(){return this->_linkType;}
    inline void setlinkType(LinkType newLinkType) {_linkType  = newLinkType;}

signals:

private:
   QString  _linkName;
   LinkType _linkType;

};

typedef QSharedPointer<LinkConfig> LinkConfigPtr;
typedef QSharedPointer<LinkInterface> LinkInterfacePtr;

#endif // LINKCONFIG_H
