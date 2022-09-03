#ifndef FREEKAPPLICATION_H
#define FREEKAPPLICATION_H

#include <QApplication>
#include <QObject>
#include <QQmlEngine>
class QQmlApplicationEngine;
class ModuleBox;
class ScreenTool;
///
/// \brief The FreeKApplication class
/// APP应用程序
///
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
    void initAppView();
private:
    ModuleBox *              _moduleBox;
    QQmlApplicationEngine*   _qmlAppEngine;
    void                     _exitWithError    (QString errorMessage);
//
    QObject *                _creatRootObject();

    //static ScreenTool *      _creatScreen(QQmlEngine *engine, QJSEngine *scriptEngine);

    static QString _name;

};
FreeKApplication* FreeKApp(void);
#endif // FREEKAPPLICATION_H
