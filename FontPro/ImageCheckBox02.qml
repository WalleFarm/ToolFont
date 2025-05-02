import QtQuick 2.7

Rectangle
{
    property var imgSrc: "qrc:/checked.png"
    property var isChecked: 0
    property var directValue: 0
    property var textValue: "名称"
    property var textColor: "black"
    property var textHorizontalAlignment: Text.AlignHCenter
    signal siqChecked(var check_state)
    width: height  
    height: 30
    border.width: 1
    border.color: "#808080"
    radius: 2
    Image
    {
        id:id_checkImg
        anchors.fill: parent
        anchors.margins: 2
        mipmap: true
        source: isChecked>0 ? imgSrc : ""        
        MouseArea
        {
            anchors.fill: parent
            onClicked: 
            {
                isChecked = !isChecked
                siqChecked(isChecked)
            }
        }       
    }
//    onIsCheckedChanged: 
//    {
//        siqChecked(isChecked)
//    }
    Text{
        id:id_checkText
        height: parent.height
        width: height*2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: textHorizontalAlignment
        font.pointSize: height*0.5
        font.family:"宋体"
        color: textColor
        text:textValue
    }
   Component.onCompleted: 
   {
        switch(directValue)
        {
            case 0:
                id_checkText.anchors.horizontalCenter=id_checkImg.horizontalCenter
                id_checkText.anchors.bottom=id_checkImg.top
                break
            case 1:
                id_checkText.anchors.horizontalCenter=id_checkImg.horizontalCenter
                id_checkText.anchors.top=id_checkImg.bottom
                break
            case 2:
                id_checkText.anchors.verticalCenter=id_checkImg.verticalCenter
                id_checkText.anchors.right=id_checkImg.left
                break
            default:
                id_checkText.anchors.verticalCenter=id_checkImg.verticalCenter
                id_checkText.anchors.left =id_checkImg.right
                break
        }
   }
    function funSetCheckState(state)
    {
        isChecked=state>0
    }
    function funTakeCheckState()
    {
        return isChecked
    }
}
