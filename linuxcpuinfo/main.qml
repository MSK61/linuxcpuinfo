import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Linux CPU Info")

    ListView {
        id: lstProcessors
        width: 150
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        model: cores
        delegate: Item {
            x: 5
            width: ListView.view.width
            height: 40

            Row {
                spacing: 10

                Image {
                    source: "qrc:///SMD Generic TQFP32 Package.svg"
                    width: 40
                    height: 40
                }

                Text {
                    text: (index < 0) ? "" : ("processor #" + index)
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked:
                    if (index >= 0) parent.ListView.view.currentIndex = index
            }
        }
        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AsNeeded
        }
        onCurrentIndexChanged:
            txtCpuInfo.text = (currentIndex < 0) ? "" : model[currentIndex]
        highlight: Rectangle {
            color: "lightsteelblue"
            radius: 5
        }
    }

    ScrollView {
        anchors.left: lstProcessors.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top

        TextEdit {
            id: txtCpuInfo
            anchors.fill: parent
            readOnly: true
            selectByMouse: true
        }
    }
}
