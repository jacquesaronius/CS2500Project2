import QtQuick 2.6
import QtQuick.Controls 2.1

Rectangle {
    property alias mouseArea: mouseArea

    width: 800
    height: 600

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        ToolBar {
            id: toolbar1
            x: 8
            y: 8
            width: 198
            height: 40

            ToolButton {
                id: tbStatic
                x: 0
                y: 0
                text: qsTr("Static Routing")
            }

            ToolButton {
                id: tbDynamic
                x: 90
                y: 0
                text: qsTr("Dynamic Routing")
            }
        }

        ToolBar {
            id: toolBar
            x: 212
            y: 8
            width: 360
        }
    }
}
