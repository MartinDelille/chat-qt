import QtQuick 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Signal")

    C1.SplitView {
        anchors.fill: parent

        ListView {
            id: conversationListView
            width: parent.width * 0.33
            height: parent.height
            model: ["Albert Einstein", "Ernest Hemingway", "Hans Gude"]
            delegate: ItemDelegate {
                text: modelData
                width: parent.width
                height: avatar.implicitHeight
                leftPadding: avatar.implicitWidth + 32
                onClicked: messageView.push("qrc:/" + modelData.replace(" ", "_") + ".qml")
                Image {
                    id: avatar
                    source: "qrc:images/" + modelData.replace(" ", "_") + ".png"
                }
            }
        }

        StackView {
            id: messageView
            initialItem: "Albert_Einstein.qml"
            width: parent.width * 0.67
            height: parent.height
        }
    }
}
