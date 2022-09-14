#ifndef LINKCONFIG_H
#define LINKCONFIG_H

#include <QObject>

class LinkConfig : public QObject
{
    Q_OBJECT
public:
    explicit LinkConfig(QObject *parent = nullptr);

signals:

};

#endif // LINKCONFIG_H
