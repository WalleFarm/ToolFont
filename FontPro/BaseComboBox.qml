import QtQuick 2.6
import QtQuick.Controls 2.1

ComboBox//下拉框
{
    property var imgSrc: "qrc:/drop_down.png"
    property var textColor: "white"
    id:id_controlCbox
    height:35
    width:140
    background:Image {
        id: id_bgImg
        source: imgSrc
    }
    delegate: ItemDelegate//下拉选项
    {
        width: id_controlCbox.width
        height:id_controlCbox.height
        background:Rectangle
        {
//            border.width:2
//            border.color:Qt.rgba(0.1, 0.1, 0.1)
            color:Qt.rgba(0.8, 0.8, 0.8)//"transparent"
//            radius:2
        }
        contentItem: Label { //下拉框文字
            text: modelData
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: id_controlCbox.height*0.5
            color: "black"
        }
        highlighted: id_controlCbox.highlightedIndex === id_controlCbox.currentIndex
    }
    popup: Popup {  //下拉背景
              y: id_controlCbox.height - 1
              width: id_controlCbox.width
              implicitHeight: listview.contentHeight
              padding: 1
    
              contentItem: ListView {
                  id: listview
                  clip: true
                  model: id_controlCbox.popup.visible ? id_controlCbox.delegateModel : null
                  currentIndex: id_controlCbox.highlightedIndex
    
                  ScrollIndicator.vertical: ScrollIndicator { }
              }
    
              background: Rectangle {
                  border.width: 2
                  border.color: Qt.rgba(25/255, 25/255, 25/255)
                  color: Qt.rgba(125/255, 125/255, 125/255, 0.7)
                  radius: 2
              }
          }
    indicator:Rectangle  //箭头指示器
    {
        width:height
        height:id_controlCbox.height
        color:"transparent"
        anchors
        {
            right:id_controlCbox.right
        }
    }
    contentItem: Label { //上方文字显示
        text: id_controlCbox.displayText
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: id_controlCbox.height*0.5
        color: textColor
        background:Rectangle
        {
//            border.width:1
//            border.color:Qt.rgba(0, 0, 0.6)
            color:"transparent"
//            radius:4
        }
    }
    model: ListModel
    {
        id:id_dataModel
    }
    function funAddData(name)
    {
        id_dataModel.append({"name":name})
    }
    function funClearData()
    {
        id_dataModel.clear()
    }    
    function funUpdateData(index, name)
    {
        id_dataModel.setProperty(index, "name", name)
    }

}
