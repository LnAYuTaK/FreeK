#include "SerialLink.h"

SerialLinkConfig::SerialLinkConfig(const QString &linkName)
    :LinkConfig(linkName)
    ,_linkType(SerialLinkType)
{

}
//--------------------------------------------------------
void
SerialLinkConfig::setBaud(int baud)
{
    _baud = baud;
}
//--------------------------------------------------------
void
SerialLinkConfig::setDataBits(int databits)
{
    _dataBits = databits;
}
//--------------------------------------------------------
void
SerialLinkConfig::setFlowControl(int flowControl)
{
    _flowControl = flowControl;
}
//--------------------------------------------------------
void
SerialLinkConfig::setStopBits(int stopBits)
{
    _stopBits = stopBits;
}
//--------------------------------------------------------
void
SerialLinkConfig::setParity(int parity)
{
    _parity = parity;
}
//--------------------------------------------------------
void
SerialLinkConfig::setPortName(const QString& portName)
{
    //正在连接的连接无影响
    QString pname = portName.trimmed();
    if (!pname.isEmpty() && pname != _portName) {
        _portName = pname;
    }
}
//--------------------------------------------------------
void
SerialLinkConfig::setUsbDirect(bool usbDirect)
{
    if (_usbDirect != usbDirect) {
        _usbDirect = usbDirect;
    }
}
//--------------------------------------------------------
SerialLink::SerialLink(LinkConfigPtr &conf)
    : LinkInterface(conf)
    ,_serial(nullptr)
    ,_serialConfig(qobject_cast<SerialLinkConfig *>(conf.data()))
    ,_serialIsConnected(false)
{

}
//--------------------------------------------------------
SerialLink::~SerialLink()
{



}
//--------------------------------------------------------
void
SerialLink::_writeBytes  (const QByteArray data)
{
    if(_serial) {
        _serial->write(data);
        emit bytesSend(this,data);
    }
}
//--------------------------------------------------------
void
SerialLink::_readBytes()
{
   emit bytesReceived(this, 0);
}
//--------------------------------------------------------
bool
SerialLink::connect()
{

    emit connected();
    return _serialIsConnected;
}
//--------------------------------------------------------
bool
SerialLink::_isBootloader()
{
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    if( portList.count() == 0) {
        return false;
    }
    for (const QSerialPortInfo &info: portList) {

        if (info.portName().trimmed() == _serialConfig->portName() &&
                (info.description().toLower().contains("bootloader") ||
                 info.description().toLower().contains("px4 bl") ||
                 info.description().toLower().contains("px4 fmu v1.6"))) {
            return true;
        }
    }
    return false;
}




