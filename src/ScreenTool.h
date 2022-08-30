#ifndef SCREENTOOL_H
#define SCREENTOOL_H

#include <QObject>
///屏幕显示配置
class ScreenTool : public QObject
{
    Q_OBJECT
public:
    ScreenTool();
    Q_PROPERTY(bool     isAndroid               READ isAndroid              CONSTANT)
    Q_PROPERTY(bool     isIOS                   READ isIOS                  CONSTANT)
    Q_PROPERTY(bool     isLinux                 READ isLinux                CONSTANT)
    Q_PROPERTY(int      defaultHeight           READ defaultHeight          NOTIFY defaultHeightChanged)
    Q_PROPERTY(int      defaultWidth            READ defaultWidth           NOTIFY defaultWidthChanged)
    Q_PROPERTY(QString  defalutFrontFamily      READ defalutFrontFamily     NOTIFY defalutFrontFamilyChanged)
    Q_PROPERTY(int      defaultFontPixelWidth   READ defaultFontPixelWidth  NOTIFY defaultFontPixelWidthChanged)
    Q_PROPERTY(int      defaultToolBarHeight    READ defaultToolBarHeight   NOTIFY defaultToolBarHeightChanged)

private:
    //字体
    enum FrontFamily{

    };

    int      defaultWidth         ()           {return _defaultWidth;}
    int      defaultHeight        ()           {return _defaultHeight;}
    QString  defalutFrontFamily   ()           {return _defalutFrontFamily;}
    int      defaultFontPixelWidth()           {return _defaultFontPixelWidth;}
    int      defaultToolBarHeight ()            {return _defaultToolBarHeight;}


    static int      _defaultWidth ;
    static int      _defaultHeight;
    static QString  _defalutFrontFamily;
    static int      _defaultFontPixelWidth;
    static int      _defaultToolBarHeight;

    bool isAndroid() {
    #ifdef Q_OS_ANDROID
          return true;
    #else
          return false;
    #endif
    }

    bool isLinux() {
    #ifdef Q_OS_LINUX
          return true;
    #else
          return false;
    #endif
    }

    bool isIOS() {
    #ifdef Q_OS_IOS
          return true;
    #else
          return false;
    #endif
    }



signals:
   void  defaultWidthChanged();
   void  defaultHeightChanged();
   void  defalutFrontFamilyChanged();
   void  defaultFontPixelWidthChanged();
   void  defaultToolBarHeightChanged();

};

#endif // SCREENTOOL_H
