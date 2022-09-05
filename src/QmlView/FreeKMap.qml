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
    property string mapName:   "FreeKDefatltMap"
    //更新显示地图
    function updateMapType(mapProvider,mapType) {
         var fullMapName = mapProvider + " " + mapType
            for (var i = 0; i < _map.supportedMapTypes.length; i++) {
                if (fullMapName === _map.supportedMapTypes[i].name) {
                    _map.activeMapType = _map.supportedMapTypes[i]
                }
            }
    }
}



