#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>

#include "ModuleBox.h"
#include "LinkConfig.h"
#include "LinkInterface.h"
class FreeKApplication;

///
/// \brief The LinkManager class
///负责生成并管理Link
class LinkManager : public Module
{
    Q_OBJECT
public:
    LinkManager(FreeKApplication *app , ModuleBox  * moduleBox);

    void setModuleBox (ModuleBox  * moduleBox)override;

    void createLink(LinkConfigPtr &conf);

private:
    QList<LinkConfigPtr>    _LinkConfigList;
    QList<LinkInterfacePtr> _LinkInterfaceList;

};



#endif // LINKMANAGER_H
