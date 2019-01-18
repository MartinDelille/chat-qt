import QtQuick 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4

import ai.lipr.chat 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Chat Qt")

    C1.SplitView {
        anchors.fill: parent

        ContactModel {
            id: contactModel
        }

        ListView {
            id: conversationListView
            width: parent.width * 0.33
            height: parent.height
            model: contactModel
            delegate: ItemDelegate {
                text: model.name
                width: parent.width
                height: avatar.implicitHeight
                leftPadding: avatar.implicitWidth + 32
                onClicked: messageView.inConversationWith = model.name
                Image {
                    id: avatar
                    source: "qrc:images/" + model.name.replace(" ", "_") + ".png"
                }
            }
        }

        ConversationView {
            id: messageView
            inConversationWith: "Albert Einstein"
            width: parent.width * 0.67
            height: parent.height
        }
    }
}
