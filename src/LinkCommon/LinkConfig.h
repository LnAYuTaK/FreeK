#ifndef LINKCONFIG_H
#define LINKCONFIG_H

#include <QObject>
class LinkInterface;
///
/// \brief The LinkConfig class
/// 连接配置的基类
class LinkConfig : public QObject
{
    Q_OBJECT
public:
    enum LinkType{
        TCPLinkType,
        UDPLinkType,
        SerialLinkType,
        BlueToothLinkType,
        DefaultLinkType
    };
    Q_ENUM(LinkType)

    LinkConfig(const QString &linkName);

    inline QString linkName(){return this->_linkName;}
    inline void setLinkName(QString &newLinkName) { if(newLinkName!="")  _linkName =newLinkName;}
    //Needs to be implemented
    virtual inline LinkType type()const =0 ;
signals:

private:
   QString  _linkName;
};

typedef QSharedPointer<LinkConfig>    LinkConfigPtr;
typedef QSharedPointer<LinkInterface> LinkInterfacePtr;

#endif // LINKCONFIG_H
