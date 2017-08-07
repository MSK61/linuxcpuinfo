import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2

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
                    text: (index < 0) ? "" : ("processor #" + getProcessorNum())
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true

                    function getProcessorNum() {
                        var found = modelData.find(function(prop) {

                            return prop.name === "processor";

                        });

                        return found ? found.value : index;

                    }
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
        onCurrentIndexChanged: tblCpuInfo.model = (currentIndex < 0) ?
                                   emptyModel : model[currentIndex]
        highlight: Rectangle {
            color: "lightsteelblue"
            radius: 5
        }

        ListModel {
            id: emptyModel
        }
    }

    TableView {
        id: tblCpuInfo
        headerVisible: false
        anchors.left: lstProcessors.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        itemDelegate: TextInput {
            text: styleData.value
            readOnly: true
            selectByMouse: true
            autoScroll: false
        }

        TableViewColumn {
            id: propNameCol
            role: "name"
        }

        TableViewColumn {
            role: "value"
            width: tblCpuInfo.width - propNameCol.width
        }
    }
}
