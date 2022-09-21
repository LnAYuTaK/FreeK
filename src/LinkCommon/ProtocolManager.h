#ifndef PROTOCOLMANAGER_H
#define PROTOCOLMANAGER_H

#include <QObject>
#include "ModuleBox.h"
class FreeKApplication;
///
/// \brief The ProtocolManager class
///
class ProtocolManager : public Module
{
    Q_OBJECT
public:
    ProtocolManager(FreeKApplication *app , ModuleBox  * moduleBox);

    void  setModuleBox(ModuleBox  * moduleBox)override;

private:

signals:

};

#endif // PROTOCOLMANAGER_H
