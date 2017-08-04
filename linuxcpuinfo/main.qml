import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Linux CPU Info")

    ScrollView {
        anchors.fill: parent

        TextEdit {
            anchors.fill: parent
            readOnly: true
            text: _infoAgent.getInfo()
            selectByMouse: true
        }
    }
}
