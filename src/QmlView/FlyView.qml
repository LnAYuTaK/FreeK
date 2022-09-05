import QtQuick 2.11
import QtQuick          2.3
import QtQuick.Controls 1.2
import QtLocation       5.3
import QtPositioning    5.3
import QtQuick.Dialogs  1.2
import QtPositioning 5.2
import QtLocation 5.2
import FreeK.MapEngineManager 1.0
//飞行


Item {
    id: _root
    property var    map:  _map
    FreeKMap{
        id:_map
        anchors.fill :parent
    }

}
