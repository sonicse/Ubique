import Qt 4.6

Rectangle {
    id: itemId
    width: 200
    height: 200
    Text {
        x: 66
        y: 93
        text: "Hello World"
    }
    Image {
        source: "images/test.jpg"
        anchors.fill: parent
    }

    signal clicked();

    MouseArea {
        //onClicked: itemId.clicked();
        onClicked: console.log("clicked");
        anchors.fill: parent
    }


}
