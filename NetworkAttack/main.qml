import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    MainForm {
        id: mainform
        anchors.fill: parent
        Label {
            id: lblKvalue
            x: 363
            y: 575
            text: mainform.sliderKValue.valueAt(mainform.sliderKValue.position).toFixed();
        }
        Connections {
                target: controller
                onUpdate: {
                    mainform.lblRounds.text = controller.rounds;
                    mainform.txtStatus.text = mainform.txtStatus.text + controller.status + "\n";
                }

        }


    }



}
