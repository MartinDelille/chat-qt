import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

Page {
    id: root

    property string inConversationWith

    header: ToolBar {
        Label {
            id: pageTitle
            text: inConversationWith
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
}
