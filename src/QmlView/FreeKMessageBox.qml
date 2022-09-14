import QtQuick 2.6
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

// MessageBox iOS
Rectangle {
    property var main
    property alias title:	titleMsg.text
    property alias text:	textMsg.text

    signal buttonClick (int index, string name)

    function open(object){
        visible = true;
        if(object){
            main = object;

        }
    }
    function close(object){
        visible = false;
        if(object) object.enabled = true;
        else if(main) main.enabled = true;
    }
    function addButtons(arr){
        if(Array.isArray(arr)){
            dataModel.clear();
            for(var i = 0; i < arr.length; i++) dataModel.append(arr[i]);
        }
    }

    id:				msgbox
    anchors.fill:	parent
    visible:		false
    color:			"transparent"
    z:				1000

    Rectangle {
        anchors.fill:	parent
        color:			"black"
        opacity:		0.4
        z:				1
    }
    Rectangle {
        property real defH: (titleMsg.contentHeight + textMsg.contentHeight) * 2
        id:						msg
        x:						((parent.width / 2) - (this.width / 2))
        y:						((parent.height / 2) - (this.height / 2))
        clip:					true
        radius:					8
        opacity:				0.9
        width:					250
        implicitHeight:			(defH < 135 ? 135 : defH)
        anchors.leftMargin:		63
        anchors.rightMargin:	anchors.leftMargin
        color:					"white"
        z:						2
        onHeightChanged: {
            if(msgbox.height){
                var rateHScreen = (msgbox.height / 2);
                if(implicitHeight > rateHScreen){
                    implicitHeight = rateHScreen;
                    textMsg.minimumPointSize = 5;
                }
            }
        }

        Rectangle {
            id:						texts
            anchors.fill:			parent
            anchors.margins:		(parent.width / 15)
            anchors.bottomMargin:	buttons.height
            color:					"transparent"

            Label {
                id:						titleMsg
                width:					parent.width
                minimumPointSize:		10
                font.pointSize:			16
                font.bold:				true
                font.family:			"Tahoma"
                fontSizeMode:			Text.Fit;
                horizontalAlignment:	Text.AlignHCenter
                wrapMode:				Text.WordWrap
                clip:					true
                color:					"black"
                text:					qsTr("Title")
            }

            Label {
                id:						textMsg
                anchors.fill:			parent
                anchors.topMargin:		(titleMsg.contentHeight + (titleMsg.contentHeight * 30 / 100))
                width:					parent.width
                font.pointSize:			13
                font.family:			"Tahoma"
                fontSizeMode:			Text.Fit;
                horizontalAlignment:	Text.AlignHCenter
                wrapMode:				Text.WordWrap
                clip:					true
                color:					"black"
                text:					qsTr("Text")
            }
        }
        Rectangle {
            id:					buttons
            y:					(texts.height + texts.anchors.topMargin)
            width:				parent.width
            height:				45
            anchors.margins:	0
            color:				"transparent"
            Rectangle {
                x:			0
                y:			0
                width:		parent.width
                height:		2
                color:		"#d9d9d9"
                visible:	(dataModel.count > 1)
            }

            ListView {
                id:				list
                width:			parent.width
                height:			parent.height
                model:			dataModel
                clip:			true

                delegate: Item {
                    Rectangle {
                        x:		(model.index ? this.width * model.index : 0)
                        width:	(buttons.width / dataModel.count)
                        height:	buttons.height
                        color:	"transparent"
                        Rectangle {
                            x:			parent.width - this.width
                            y:			0
                            width:		2
                            height:		parent.height
                            color:		"#d9d9d9"
                            visible:	(model.index < (dataModel.count - 1))
                        }
                        Label {
                            anchors.fill:			parent
                            anchors.margins:		5
                            minimumPointSize:		5
                            font.pointSize:			16
                            font.bold:				(model["default"] || (dataModel.count === 1) ? true : false)
                            font.family:			"Tahoma"
                            fontSizeMode:			Text.Fit;
                            horizontalAlignment:	Text.AlignHCenter
                            verticalAlignment:		Text.AlignVCenter
                            wrapMode:				Text.WordWrap
                            clip:					true
                            color:					"#00cc33"
                            text:					model.text
                        }
                        MouseArea {
                            id:				area
                            anchors.fill:	parent
                            onClicked: {
                                msgbox.visible = false;
                                msgbox.buttonClick(model.index, model.text);
                            }
                        }
                    }
                }
            }
            ListModel { id: dataModel }
        }
    }
}
