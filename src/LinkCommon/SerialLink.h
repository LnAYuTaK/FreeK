#ifndef SERIALLINK_H
#define SERIALLINK_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "LinkInterface.h"
#include "LinkConfig.h"
///
/// \brief The SerialLinkConfig class
///
class SerialLinkConfig:public LinkConfig
{
    Q_OBJECT
public:
    SerialLinkConfig(const QString &linkName);

    Q_PROPERTY(int      baud            READ baud               WRITE setBaud               NOTIFY baudChanged)
    Q_PROPERTY(int      dataBits        READ dataBits           WRITE setDataBits           NOTIFY dataBitsChanged)
    Q_PROPERTY(int      flowControl     READ flowControl        WRITE setFlowControl        NOTIFY flowControlChanged)
    Q_PROPERTY(int      stopBits        READ stopBits           WRITE setStopBits           NOTIFY stopBitsChanged)
    Q_PROPERTY(int      parity          READ parity             WRITE setParity             NOTIFY parityChanged)
    Q_PROPERTY(QString  portName        READ portName           WRITE setPortName           NOTIFY portNameChanged)
    Q_PROPERTY(bool     usbDirect       READ usbDirect          WRITE setUsbDirect          NOTIFY usbDirectChanged)

    int  baud() const         { return _baud; }
    int  dataBits() const     { return _dataBits; }
    int  flowControl() const  { return _flowControl; }
    int  stopBits() const     { return _stopBits; }
    int  parity() const       { return _parity; }
    bool usbDirect() const    { return _usbDirect; }
    QString portName() const  { return _portName; }


    void setBaud              (int baud);
    void setDataBits          (int databits);
    void setFlowControl       (int flowControl);
    void setStopBits          (int stopBits);
    void setParity            (int parity);
    void setPortName          (const QString& portName);
    void setUsbDirect         (bool usbDirect);

    LinkConfig::LinkType type () const override{return this->_linkType;}
signals:
    void baudChanged            ();
    void dataBitsChanged        ();
    void flowControlChanged     ();
    void stopBitsChanged        ();
    void parityChanged          ();
    void portNameChanged        ();
    void portDisplayNameChanged ();
    void usbDirectChanged       (bool usbDirect);

private:
    int _baud;
    int _dataBits;
    int _flowControl;
    int _stopBits;
    int _parity;
    QString _portName;
    QString _portDisplayName;
    bool _usbDirect;
    LinkConfig::LinkType  _linkType;

};

class SerialLink : public LinkInterface
{
    Q_OBJECT
public:
    SerialLink(LinkConfigPtr &conf);
    ~SerialLink();

    Q_INVOKABLE void disconnect            () override{};
    Q_INVOKABLE bool connect               () override;

    inline bool isConnected                () const override{return _serialIsConnected;}
    inline SerialLinkConfig * serialConfig () {return this->_serialConfig;};

private slots:
    void _readBytes   ();
    void _writeBytes  (const QByteArray data)override;

private:
    bool                 _isBootloader();

    QSerialPort *        _serial;
    SerialLinkConfig *   _serialConfig;
    bool                 _serialIsConnected;

};

#endif // SERIALLINK_H
