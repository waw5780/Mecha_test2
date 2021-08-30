import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4 as TabView

TabView.Tab{
    title: "Minimum Setting"
    Item{
        anchors.fill: parent
        anchors.margins: 20

        Label{
            id: minimumSettingTitle
            text: "Feeder Minimum Find Test Setting"
            font.pixelSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Column{
            spacing: 10

            anchors{
                top: minimumSettingTitle.bottom
                left: parent.left
                topMargin: 50
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Initial Percentage "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.initPer
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.initPer = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "First Find Step "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.firstStep
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.firstStep = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Second Find Step "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.secondStep
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.secondStep = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Minimum Range "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.minimumRange
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.minimumRange = text
                    }
                }
            }
        }
        Column{
            id: minimumSettingSecondColumn
            spacing: 10

            anchors{
                top: minimumSettingTitle.bottom
                right: parent.right
                topMargin: 50
            }
            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Minimum Gram/min "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.targetGramPerMin
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.targetGramPerMin = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Minimum Find Count "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.findCount
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.findCount = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Minimum Measure Time "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.findSec
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.findSec = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Final Test Count "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederMini.finalFindCount
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederMini.finalFindCount = text
                    }
                }
            }
        }

        Column {
            spacing: 10
            anchors {
                top: minimumSettingSecondColumn.bottom
                topMargin: 60
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            Row {
                width: parent.width
                spacing: 60
                Label {
                    text: "Feeder1"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederMini.miniFeeder1Test
                    onCheckedChanged: feederMini.miniFeeder1Test = checked
                }

                Label {
                    text: "Feeder2"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederMini.miniFeeder2Test
                    onCheckedChanged: feederMini.miniFeeder2Test = checked
                }

                Label {
                    text: "Feeder3"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederMini.miniFeeder3Test
                    onCheckedChanged: feederMini.miniFeeder3Test = checked
                }
            }

            Row {
                width: parent.width
                spacing: 60
                Label {
                    text: "Feeder4"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederMini.miniFeeder4Test
                    onCheckedChanged: feederMini.miniFeeder4Test = checked
                }

                Label {
                    text: "Feeder5"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederMini.miniFeeder5Test
                    onCheckedChanged: feederMini.miniFeeder5Test = checked
                }

                Label {
                    text: "Feeder6"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederMini.miniFeeder6Test
                    onCheckedChanged: feederMini.miniFeeder6Test = checked
                }
            }
        }
    }
}
