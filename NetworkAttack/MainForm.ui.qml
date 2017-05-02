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
                width: 129
                height: 40
                stepSize: 10
                from: 10
                to: 1000
                value: 10
            }

            Slider {
                id: sliderDelay
                x: 223
                y: 0
                width: 129
                height: 40
                stepSize: 10
                from: 10
                to: 1000
                value: 10

                ToolButton {
                    id: tbCreate
                    x: 129
                    y: 0
                    text: qsTr("Create Network")
                }
            }

            ToolButton {
                id: tbBaseAttack
                x: 0
                y: 0
                text: qsTr("Base Attack")
                checkable: true
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
    }
}
