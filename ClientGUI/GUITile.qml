import QtQuick 1.1

Item {
    id: tile
    width: 40
    height: 40

    Image {
     //fill in based on Grid sent from Client
        source: "resources/black.png"
    }

    MouseArea {
     anchors.fill: parent
     onClicked: {
        // Need to send signal
     }
    }
}
