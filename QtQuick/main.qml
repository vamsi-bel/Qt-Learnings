import QtQuick
Window {
    id: root
    title: qsTr("Nested Layouts")
    width: 800; height: 400
    visible: true
    color: "gray"
    Rectangle {
        x: 50; y: 50
        width: parent.width/6
        height: parent.height - 2*y
        color: "lightblue"
        Rectangle {
            x: 50; y: 50
            width: 58; height: 50
            color: "white"
        }
    }
    Rectangle {
        x: 250; y: 50
        width: parent.width/6
        height: (parent.height - 2*y)
        color: "green"
        Rectangle {
            x: 50; y: 50
            width: 58; height: 50
            color: "blue"
        }
    }
    Rectangle {
        id: mine
        x: 450; y: 50
        width: parent.width/6
        height: (parent.height - 2*y)
        color: "yellow"
        Rectangle {
            x: mine.horizontalCenter; y: mine.verticalCenter
            width: 58; height: 50
            color: "red"
        }
    }
}
