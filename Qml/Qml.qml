import Qt 4.6

Rectangle {
    id: screen
    width: 480
    height: 800
    color: "#343434";

    Image { source: "images/stripes.png"; fillMode: Image.Tile; anchors.fill: parent; opacity: 0.3 }

    Loading { anchors.centerIn: parent; visible: contentModel.status == 2 }

    Component {
        id: highlight
        Rectangle {
            color: "white";
            opacity: index % 2 ? 0.6 : 0.4;
        }
    }

    ListDelegate { id: listDelegate }

    ListView {
        id: listview
        model: contentModel
        delegate: listDelegate
        highlight: highlight
        focus: true
        anchors.fill: parent
    }

}
