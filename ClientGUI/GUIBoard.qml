import QtQuick 2.0

Rectangle {
    width: 320
    height: 320

    Grid {
        id: boardGrid
        x: 0
        y: 0
        width: 320
        height: 320
        rows: 8
        columns: 8

        Image {
            width: 320
            height: 320
            source: "resources/grid.png"
        }

        Repeater {
            GUITile { }
        }
    }
}
