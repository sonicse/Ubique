import Qt 4.6

Rectangle {
    id: screen
    width: 480
    height: 800
    color: "white"

    Component {
        id: delegate
        Item {
            id: wrapper
            height: 50
            width: parent.width

            Text {
                text: str
            }
        }
    }

    Component {
        id: highlight

        Rectangle {
            height: 50
            width: parent.width
            color: "lightsteelblue"
        }
    }

    ListView {
        id: listview
        model: testModel
        delegate: delegate
        highlight: highlight
        focus: true
        //anchors.fill: parent
        width: parent.width; height: parent.height
    }

    ListModel {
        id: testModel

        ListElement {
            str: "Item 1"
        }

        ListElement {
            str: "Item 2"
        }

        ListElement {
            str: "Item 3"
        }
    }
}

//    Image {
//        source: "images/test.jpg"
//        anchors.fill: parent
//        fillMode: Image.PreserveAspectCrop
//    }
//
//    signal test();
//
//    MouseArea {
//        id: mouseRect
//        onClicked: itemId.test();
//        anchors.fill: parent
//    }
//
//    states: State {
//                 name: "clicked"; when: mouseRect.pressed == true
//                 PropertyChanges { target: itemId; rotation: 180 }
//             }
//
//    transitions: Transition {
//                 from: ""; to: "clicked"; reversible: true
//                 ParallelAnimation {
//                     NumberAnimation { properties: "rotation"; duration: 500; easing.type: "InOutQuad" }
//                 }
//             }
//}
