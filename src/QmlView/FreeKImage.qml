import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.12
//自定义图片
Item {

    property color color:               "white"// Image color
    property alias asynchronous:        image.asynchronous
    property alias cache:               image.cache
    property alias fillMode:            image.fillMode
    property alias horizontalAlignment: image.horizontalAlignment
    property alias mirror:              image.mirror
    property alias paintedHeight:       image.paintedHeight
    property alias paintedWidth:        image.paintedWidth
    property alias progress:            image.progress
    property alias smooth:              image.smooth
    property alias mipmap:              image.mipmap
    property alias source:              image.source
    property alias sourceSize:          image.sourceSize
    property alias status:              image.status
    property alias verticalAlignment:   image.verticalAlignment

    width:  image.width
    height: image.height

    Image {
        id:                 image
        smooth:             true
        mipmap:             true
        antialiasing:       true
        visible:            true
        fillMode:           Image.PreserveAspectFit
        anchors.fill:       parent
        anchors.centerIn:   parent
        sourceSize.height:  height
    }

}
