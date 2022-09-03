import QtQuick 2.11
import QtQuick          2.3
import QtQuick.Controls 1.2
import QtLocation       5.3
import QtPositioning    5.3
import QtQuick.Dialogs  1.2
import QtPositioning 5.2
import QtLocation 5.2
import FreeK.MapEngineManager 1.0
Map {
    id: _map
    minimumZoomLevel: 3

    readonly property real maximumZoomLevel: 20
    zoomLevel: 10
    center: QtPositioning.coordinate(37.52, 121.39)
    plugin: Plugin {name: "freekmap"}
    opacity:                    0.99
    property string mapName:   "FreeKMapDefatlt"

    //property  var mapProviderList   MapEngineManager.mapProviderList

    //更新显示地图
    function updateMapType(mapProvider,mapType) {



    }




    MapQuickItem {
        anchorPoint.x:  sourceItem.width / 2
        anchorPoint.y:  sourceItem.height / 2
        visible:        false

        sourceItem: Image {
            id:             mapItemImage
            source:         "qrc:/images/dingweizuobiao.svg"
            mipmap:         true
            antialiasing:   true
            fillMode:       Image.PreserveAspectFit
            sourceSize.height: height
        }
    }
}



