import QtQuick 2.6
import QtQuick.Controls 2.1

Rectangle {
    id: rectangle
    property alias rectangle: rectangle

    property alias lblRounds: lblRounds

    height: 600

    MouseArea {

        property alias txtStatus: txtStatus
        property alias mouseArea: mouseArea
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
            width: 120
            height: 40

            ToolButton {
                id: tbStatic
                x: 0
                y: 0
                text: qsTr("Static")
                autoExclusive: true
                checked: true
                checkable: true
            }

            ToolButton {
                id: tbDynamic
                x: 50
                y: 0
                text: qsTr("Dynamic")
                autoExclusive: true
                checkable: true
            }
        }

        ToolBar {
            id: toolBar
            x: 134
            y: 8
            width: 658
            height: 40

            Slider {
                id: sliderKValue
                x: 93
                y: 0
                width: 259
                height: 40
                stepSize: 10
                from: 10
                to: 1000
                value: 10
            }

            ToolButton {
                id: tbBaseAttack
                x: 0
                y: 0
                text: qsTr("Base Attack")
                checkable: true
            }

            ToolButton {
                id: tbCreate
                x: 352
                y: 0
                text: qsTr("Create Network")
            }

            ToolButton {
                id: tbReset
                x: 472
                y: 0
                text: qsTr("Reset Network")
            }

            ToolButton {
                id: tbAttack
                x: 585
                y: 0
                width: 73
                height: 40
                text: qsTr("Attack!")
            }
        }

        Label {
            id: label
            x: 8
            y: 575
            text: qsTr("Rounds")
        }

        Label {
            id: lblRounds
            x: 70
            y: 575
            text: qsTr("")
        }

        TextArea {
            id: txtStatus
            x: 8
            y: 54
            width: 784
            height: 515
            text: qsTr("")
        }
    }

    Connections {
        target: tbStatic
        onClicked: controller.setMode(controller.MODE_ATTACK_STATIC)
    }

    Connections {
        target: tbDynamic
        onClicked: controller.setMode(controller.MODE_ATTACK_DYNAMIC)
    }

    Connections {
        target: tbBaseAttack
        onClicked: controller.setMode(controller.MODE_ATTACK_BASE)
    }

    Connections {
        target: tbCreate
        onClicked: controller.create()
    }

    Connections {
        target: tbReset
        onClicked: controller.reset()
    }

    Connections {
        target: tbAttack
        onClicked: controller.attack()
    }
}
