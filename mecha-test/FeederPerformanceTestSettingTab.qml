import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.4 as TabView

TabView.Tab{
    title: "Performance Setting"
    Item{
        anchors.fill: parent
        anchors.margins: 20

        Label{
            id: perfomanceSettingTitle
            text: "Feeder Performance Test Setting"
            font.pixelSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Column {
            id: stepColumn1
            spacing: 10

            anchors {
                top: perfomanceSettingTitle.bottom
                topMargin: 20
                left: parent.left
                leftMargin: 50
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step1 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step1
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step1 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step2 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step2
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step2 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step3 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step3
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step3 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step4 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step4
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step4 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step5 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step5
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step5 = text
                    }
                }
            }
        }
        Column {
            spacing: 10

            anchors {
                top: perfomanceSettingTitle.bottom
                topMargin: 20
                right: parent.right
                rightMargin: 50
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step6 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step6
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step6 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step7 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step7
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step7 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step8 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step8
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step8 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step9 "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step9
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step9 = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 100
                    text: "Step10"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.step10
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.step10 = text
                    }
                }
            }
        }

        Row {
            spacing: 80
            anchors {
                top: stepColumn1.bottom
                topMargin: 30
                left: parent.left
                right: parent.right
            }
            height: 100

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Step Measure time(sec) "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.stepTime
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.stepTime = text
                    }
                }
            }

            Row{
                spacing: 10

                Label{
                    width: 180
                    text: "Step Measure Count  "
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField{
                    width: 60
                    height: 30
                    text: feederPerformance.stepCount
                    font.pixelSize: 15

                    onEditingFinished: {
                        feederPerformance.stepCount = text
                    }
                }
            }
        }
        Column {
            spacing: 10
            anchors {
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
                    checked: feederPerformance.feeder1Test
                    onCheckedChanged: feederPerformance.feeder1Test = checked
                }

                Label {
                    text: "Feeder2"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederPerformance.feeder2Test
                    onCheckedChanged: feederPerformance.feeder2Test = checked
                }

                Label {
                    text: "Feeder3"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederPerformance.feeder3Test
                    onCheckedChanged: feederPerformance.feeder3Test = checked
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
                    checked: feederPerformance.feeder4Test
                    onCheckedChanged: feederPerformance.feeder4Test = checked
                }

                Label {
                    text: "Feeder5"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederPerformance.feeder5Test
                    onCheckedChanged: feederPerformance.feeder5Test = checked
                }

                Label {
                    text: "Feeder6"
                    font.pixelSize: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                CheckBox {
                    checked: feederPerformance.feeder6Test
                    onCheckedChanged: feederPerformance.feeder6Test = checked
                }
            }
        }
    }
}
