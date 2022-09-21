#ifndef MAVLINKPROTOCOL_H
#define MAVLINKPROTOCOL_H

#include <QObject>
#include <QThread>

class LinkInterface;
///
/// \brief The MavLinkProtocol class
/// MavLink协议解析
///
class MavLinkProtocol : public QObject
{
    Q_OBJECT
public:
    MavLinkProtocol();
signals:

public slots:
    void mavReceivedBytes(LinkInterface* link, QByteArray data);
    void mavSendBytes(LinkInterface* link, QByteArray data);

private slots:



private:



};

#endif // MAVLINKPROTOCOL_H
