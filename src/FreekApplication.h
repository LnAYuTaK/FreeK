#ifndef FREEKAPPLICATION_H
#define FREEKAPPLICATION_H

#include <QApplication>
#include <QObject>
class FreeKApplication : public QApplication
{
    Q_OBJECT
public:
    FreeKApplication(int &argc, char* argv[]);
    ~FreeKApplication();

    bool event(QEvent *e) override;
    //语言翻译
    void setLanguage();


    bool checkErrorState();

    static FreeKApplication*  _app;


    QString name ;



public :
    void _initAppCommon();



};
FreeKApplication* FreeKApp(void);
#endif // FREEKAPPLICATION_H
