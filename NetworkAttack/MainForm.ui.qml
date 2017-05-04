import QtQuick 2.6
import QtQuick.Controls 2.1

Rectangle {
    property alias txtStatus: txtStatus
    property alias lblRounds: lblRounds
    id: rectangle
    width: 800

    height: 600
    property alias tbStaticAttack: tbStaticAttack
    property alias tbReset: tbReset
    property alias tbBaseAttack: tbBaseAttack
    property alias sliderKValue: sliderKValue

    MouseArea {
        property alias mouseArea: mouseArea
        width: 800
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
                text: qsTr("Reactive")
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

            ToolButton {
                id: tbBaseAttack
                x: 0
                y: 0
                text: qsTr("Base Attack")
                checked: true
                autoExclusive: true
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

            ToolButton {
                id: tbStaticAttack
                x: 94
                y: 0
                text: qsTr("Static Attack")
                autoExclusive: true
                checkable: true
            }

            ToolButton {
                id: tbDynAttack
                x: 189
                y: 0
                text: qsTr("Dynamic Attack")
                autoExclusive: true
                checked: false
                checkable: true
            }

            Slider {
                id: sliderKValue
                x: 0
                y: 546
                stepSize: 1
                from: 10
                to: 500
                orientation: Qt.Horizontal
                value: 50
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
            text: qsTr("0")
        }


        TextArea {
            id: txtStatus
            x: 8
            y: 54
            width: 784
            height: 440
            text: qsTr("")
        }

        Label {
            id: label1
            x: 344
            y: 575
            text: qsTr("K:")
        }
    }

    Connections {
        target: tbStatic
        onClicked: controller.mode = MODE_STATIC_ROUTING * 1;
    }

    Connections {
        target: tbDynamic
        onClicked: controller.mode = MODE_REACTIVE_ROUTING * 1;
    }

    Connections {
        target: tbDynAttack
        onClicked: controller.attackMode = MODE_REACTIVE_ATTACK * 1;
    }

    Connections {
        target: tbStaticAttack
        onClicked: controller.attackMode = MODE_STATIC_ATTACK * 1;
    }

    Connections {
        target: tbDynAttack
        onClicked: controller.attackMode = MODE_REACTIVE_ATTACK * 1;
    }

    Connections {
        target: tbBaseAttack
        onClicked: controller.attackMode = MODE_BASE_ATTACK * 1;
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
        onClicked: controller.kvalue = sliderKValue.value
    }

    Connections {
        target: tbAttack
        onClicked: controller.attack()
    }


}
