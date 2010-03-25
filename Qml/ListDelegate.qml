import Qt 4.6

Component {
    Item {
        id: wrapper; width: wrapper.ListView.view.width; height: 86
        Item {
            id: moveMe
            Rectangle { color: "black"; opacity: index % 2 ? 0.2 : 0.4; height: 84; width: wrapper.width; y: 1 }
            Rectangle {
                x: 6; y: 4; width: 77; height: 77; color: "white"; smooth: true

                Image {
                    id: imageItem
                    source: "images/icon_default_cover.png";
                    x: 1
                    y: 1
                    width: 75
                    height: 75
                    fillMode: Image.Stretch
                }
                Image { source: "images/gloss.png" }
            }
            Column {
                x: 92; width: wrapper.ListView.view.width - 95; y: 15; spacing: 2
                Text { text: title; color: "white"; width: parent.width; font.bold: true; elide: Text.ElideRight; style: Text.Raised; styleColor: "black" }
                Text { text: href; width: parent.width; elide: Text.ElideLeft; color: "#cccccc"; style: Text.Raised; styleColor: "black" }
                Text { text: "photoDate"; width: parent.width; elide: Text.ElideRight; color: "#cccccc"; style: Text.Raised; styleColor: "black" }
            }
        }

        MouseArea {
            anchors.fill: wrapper;
            //onClicked: { view.onClicked(index); }
            onDoubleClicked: { view.onDoubleClicked(index); }
        }
    }
}
