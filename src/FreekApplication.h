#ifndef FREEKAPPLICATION_H
#define FREEKAPPLICATION_H

#include <QApplication>
#include <QObject>
class QQmlApplicationEngine;
class ModuleBox;

class FreeKApplication : public QApplication
{
    Q_OBJECT
public:
    FreeKApplication(int &argc, char* argv[]);
    ~FreeKApplication();

    bool event(QEvent *e) override;
    bool checkErrorState();
    static FreeKApplication*  _app;
    QString name()           {return _name;}

    ModuleBox * moduleBox(){return _moduleBox;}
public :
    void initAppCommon();

private:
    ModuleBox *              _moduleBox;
    QQmlApplicationEngine*   _qmlAppEngine;
    void                     _exitWithError    (QString errorMessage);
//
    QObject *                _creatRootObject();
    static QString _name;

};
FreeKApplication* FreeKApp(void);
#endif // FREEKAPPLICATION_H
