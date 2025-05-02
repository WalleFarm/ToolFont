import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Item {
    anchors.fill: parent
    MsgDialog02
    {
        id:id_msgDialog
    }
    
    //倍体选择
    Label{
        id:id_fontMxLabel
        anchors{
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: -100
            top:parent.top
            topMargin: 20
            
        }
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        font.family:"黑体"
        
        color: "black"
        text:"字体倍数:"
    }
    BaseComboBox{
        id:id_fontMxComboBox
        anchors
        {
            verticalCenter:id_fontMxLabel.verticalCenter
            left:id_fontMxLabel.right
            leftMargin:5
        }
        onCurrentValueChanged: 
        {

        }
    }
    
    //转换按钮
    BaseButton02{
        id:id_convertButton
        width: 120
        height: 40
        buttonText: "开始转换"
        anchors{
            left: id_fontMxComboBox.right
            leftMargin: 30
            verticalCenter: id_fontMxComboBox.verticalCenter
        }
        onSiqClickedLeft: {
            var font_mx = id_fontMxComboBox.currentIndex
            theMainInterface.convertAcsii2Hex(font_mx)
        }
    }
    
    
    //启用字符选择
    Rectangle{
        id:id_selectRect
        border.width: 1
        border.color: "black"
        radius: 2
        height: 500
        width: 900
        anchors{
            left: parent.left
            leftMargin: 20
            top: parent.top
            topMargin: 60
        }
        
        Column{
        
            anchors.fill: parent
            anchors.margins: 10
            spacing: 20
            Repeater{
                model: ListModel
                {
                    id:id_listModel
                } 
                RowCheckBox{
                    minCharVal: min_val
                    maxCharVal: max_val
                } 
            }
        } 
    }
    
    
    Component.onCompleted: 
    {
        for(var i=0; i<8; i++)
        {
            id_fontMxComboBox.funAddData(i+1+"倍体")
            id_fontMxComboBox.currentIndex = 0
        }
        
        id_listModel.append({"min_val":32, "max_val":47})
        id_listModel.append({"min_val":48, "max_val":57})
        id_listModel.append({"min_val":58, "max_val":64})
        id_listModel.append({"min_val":65, "max_val":90})
        id_listModel.append({"min_val":91, "max_val":96})
        id_listModel.append({"min_val":97, "max_val":122})
        id_listModel.append({"min_val":123, "max_val":126})
    }
    

    Connections{
        target: theMainInterface
        onSiqShowMsg:
        {
            id_msgDialog.funOpen(msg)
        }
    }
    
}
