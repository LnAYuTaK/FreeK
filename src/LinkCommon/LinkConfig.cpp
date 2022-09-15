#include "LinkConfig.h"

LinkConfig::LinkConfig(QString &,LinkType)
    :QObject(nullptr)
    ,_linkName("Link")
    ,_linkType(LinkType::DefaultLink)
{


}
