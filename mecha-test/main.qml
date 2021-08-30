import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4 as TabView

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("MX-LAB Feeder Test")

    TabView.TabView{
        anchors.fill: parent
        TabView.Tab{
            title: "Start/Stop"
            width: parent.width
            Item{
                id: topItem
                anchors.fill: parent
                anchors.margins: 20

                Row{
                    id: titleRow
                    spacing: 10
                    width: parent.width
                    Label{
                        anchors.right: parent.horizontalCenter
                        text: "Now Test  "
                        font.pixelSize: 25
                        font.bold: true

                    }
                    Label{
                        anchors.left: parent.horizontalCenter
                        text: mainUi.nowTest
                        font.pixelSize: 25
                        font.bold: true
                    }
                }

                Column{
                    id: stateColumn
                    anchors{
                        top: titleRow.bottom
                        topMargin: 60
                        margins: 20
                        horizontalCenter: titleRow.horizontalCenter
                    }

                    spacing: 10

                    Row{
                        spacing: 10

                        Label{
                            width: 180
                            text: "Now Feeder Number "
                            font.pixelSize: 15
                        }
                        Label{
                            text: mainUi.nowFeederNum
                            font.pixelSize: 15
                        }
                    }
                    Row{
                        spacing: 10

                        Label{
                            width: 180
                            text: "Now Feeder Percentage "
                            font.pixelSize: 15
                        }
                        Label{
                            text: mainUi.nowFeederPer
                            font.pixelSize: 15
                        }
                    }
                    Row{
                        spacing: 10

                        Label{
                            width: 180
                            text: "Scale Weight "
                            font.pixelSize: 15
                        }
                        Label{
                            text: mainUi.nowScaleWeight
                            font.pixelSize: 15
                        }
                    }
                    Row{
                        spacing: 10

                        Label{
                            width: 180
                            text: "Powder Gas "
                            font.pixelSize: 15
                        }
                        Label{
                            text: mainUi.nowGas
                            font.pixelSize: 15
                        }
                    }
                }
                Row {
                    id: gasRow
                    spacing: 10
                    width: parent.width
                    anchors {
                        top: stateColumn.bottom
                        topMargin: 60
                    }

                    Label {
                        width: 180
                        text: "Powder Gas "
                        font.pixelSize: 15
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    TextField {
                        width: 60
                        height: 30
                        text: mainUi.powderGas
                        font.pixelSize: 15
                        onEditingFinished: {
                            mainUi.powderGas = text
                        }
                    }
                }

                Grid{
                    id: controlButtons
                    anchors{
                        top: gasRow.bottom
                        topMargin: 60
                        margins: 20
                    }
                    width: 580
                    height: 110
                    columns: 3
                    rows: 2
                    spacing: 10
                    Button {
                        id: feederCleaningButton
                        width: 180
                        height: 50
                        text: "Feeder Cleaning On"
                        background: Rectangle{
                            color: feederCleaningButton.pressed ? "gray" : "dark gray"
                        }
                        onReleased: mainUi.feederCleaningOnRequest()
                    }
                    Button {
                        id: gasOnButton
                        width: 180
                        height: 50
                        // text: "Gas %1".arg(mainUi.nowGasOn ? "off" : "on")
                        text: mainUi.nowGasOn
                        background: Rectangle{
                            color: gasOnButton.pressed ? "gray" : "dark gray"
                        }
                        onReleased: mainUi.nowGasOn ? mainUi.gasOffRequest() : mainUi.gasOnRequest()
                    }
                    Button {
                        id: feederResetButton
                        width: 180
                        height: 50
                        text: "Feeder Reset"
                        background: Rectangle{
                            color: feederResetButton.pressed ? "gray" : "dark gray"
                        }
                        onReleased: mainUi.feederResetRequest()
                    }
                    Button {
                        id: minimumTestStartButton
                        width: 180
                        height: 50
                        text: "Minimum Test Start"
                        background: Rectangle{
                            color: minimumTestStartButton.pressed ? "gray" : "dark gray"
                        }
                    }
                    Button {
                        id: perfomanceTestStartButton
                        width: 180
                        height: 50
                        text: "Performance Test Start"
                        background: Rectangle{
                            color: perfomanceTestStartButton.pressed ? "gray" : "dark gray"
                        }
                    }
                    Button {
                        id: allTestStartButton
                        width: 180
                        height: 50
                        text: "All Test Start"
                        background: Rectangle{
                            color: allTestStartButton.pressed ? "gray" : "dark gray"
                        }
                        onReleased: mainUi.start()
                    }

                }
            }
        }

        FeederMinimumFindSettingTab{
            // TODO Update
        }

        FeederPerformanceTestSettingTab{
            // TODO Update
        }
    }
}
