#ifndef SCREENTOOL_H
#define SCREENTOOL_H

#include <QObject>
///
///\brief The ScreenTool class
///屏幕显示配置
///
class ScreenTool : public QObject
{
    Q_OBJECT
public:
    ScreenTool();
    Q_PROPERTY(bool     isAndroid               READ isAndroid              CONSTANT)
    Q_PROPERTY(bool     isIOS                   READ isIOS                  CONSTANT)
    Q_PROPERTY(bool     isLinux                 READ isLinux                CONSTANT)
    Q_PROPERTY(int      defaultHeight           READ defaultHeight          WRITE setDefalutHeight          NOTIFY defaultHeightChanged)
    Q_PROPERTY(int      defaultWidth            READ defaultWidth           WRITE setDefaultWidth           NOTIFY defaultWidthChanged)
    Q_PROPERTY(QString  defalutFrontFamily      READ defalutFrontFamily     WRITE setDefalutFrontFamily     NOTIFY defalutFrontFamilyChanged)
    Q_PROPERTY(int      defaultFontPixelWidth   READ defaultFontPixelWidth  WRITE setDefaultFontPixelWidth  NOTIFY defaultFontPixelWidthChanged)
    Q_PROPERTY(int      defaultToolBarHeight    READ defaultToolBarHeight   WRITE setDefaultToolBarHeight   NOTIFY defaultToolBarHeightChanged)

    Q_INVOKABLE void    setDefalutHeight(int value)           {this->_defaultHeight=value,         emit defaultHeightChanged() ;}
    Q_INVOKABLE void    setDefaultWidth(int value)            {this->_defaultWidth=value,          emit defaultWidthChanged() ;}
    Q_INVOKABLE void    setDefalutFrontFamily(QString value)  {this->_defalutFrontFamily=value,    emit defalutFrontFamilyChanged() ;}
    Q_INVOKABLE void    setDefaultFontPixelWidth(int value)   {this->_defaultFontPixelWidth=value, emit defaultFontPixelWidthChanged() ;}
    Q_INVOKABLE void    setDefaultToolBarHeight(int value)    {this->_defaultToolBarHeight=value,  emit defaultToolBarHeightChanged() ;}
private:
    //字体
    enum FrontFamily{
    };
    Q_ENUM(FrontFamily)
    //Get
    int      defaultWidth         ()               {return _defaultWidth;}
    int      defaultHeight        ()               {return _defaultHeight;}
    QString  defalutFrontFamily   ()               {return _defalutFrontFamily;}
    int      defaultFontPixelWidth()               {return _defaultFontPixelWidth;}
    int      defaultToolBarHeight ()               {return _defaultToolBarHeight;}

    //Value
    static int      _defaultHeight;
    static int      _defaultWidth ;
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
