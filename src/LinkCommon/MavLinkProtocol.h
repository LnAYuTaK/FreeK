#ifndef MAVLINKPROTOCOL_H
#define MAVLINKPROTOCOL_H

#include <QObject>

#include "ModuleBox.h"

class FreeKApplication;
class LinkInterface;
///
/// \brief The MavLinkProtocol class
/// MavLink协议解析
///
class MavLinkProtocol : public Module
{
    Q_OBJECT
public:
    MavLinkProtocol(FreeKApplication *app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox  * moduleBox)override ;

signals:


public slots:
    void mavReceivedBytes(LinkInterface* link, QByteArray data);
    void mavSendBytes(LinkInterface* link, QByteArray data);

private slots:



private:



};

#endif // MAVLINKPROTOCOL_H
