#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>

#include "ModuleBox.h"
#include "LinkConfig.h"
#include "LinkInterface.h"

class FreeKApplication;
class MavLinkProtocol;
///
/// \brief The LinkManager class
///负责生成并管理Link
///
class LinkManager : public Module
{
    Q_OBJECT
public:
    LinkManager(FreeKApplication * app , ModuleBox  * moduleBox);
    void setModuleBox (ModuleBox * moduleBox)override;

private: 
    //创建Link配置统一接口
    LinkConfigPtr _createLinkConf(QString &linkName ,int type);
    //创建Link连接接口
    bool _createLink(LinkConfigPtr conf);

    MavLinkProtocol *       _mavLinkProtocol;
    QList<LinkConfigPtr>    _LinkConfigList;
    QList<LinkInterfacePtr> _LinkInterfaceList;



};



#endif // LINKMANAGER_H
