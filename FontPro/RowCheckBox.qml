import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property var minCharVal: 48
    property var maxCharVal: 65
    id:id_rootItem
    height: 50
    width: 100
    Row{
        anchors.fill: parent
        spacing: 5
        Repeater
        {
            model: ListModel
            {
                id:id_listModel
            }    
            ImageCheckBox02{
                id:id_selectCheckBox
                directValue: 1
                textValue:  String.fromCharCode(char_val)
                width: 25
                height:25
                isChecked: 0
                onSiqChecked: {
                    if(isChecked)check_state1=true
                    else check_state1=false
                    theMainInterface.setAsciiFlag(char_val,  check_state1)
                }
                
                Timer {
                          interval: 500; running: true; repeat: true
                          onTriggered: 
                          {                             
                            if(check_state1 !== id_selectCheckBox.isChecked)
                            {
                                id_selectCheckBox.funSetCheckState(check_state1)
                                theMainInterface.setAsciiFlag(char_val,  check_state1)
                            }
                          }
                }
            }
        }
    
    }
    ImageCheckBox02{
        id:id_selectAll
        anchors{
            top: parent.top
            left: id_rootItem.right
            leftMargin: 40
        }
        directValue: 1
        textValue:  "全选"
        width: 25
        height:25
        isChecked: 0
        onSiqChecked: {
            var char_num = maxCharVal - minCharVal
            for(var i=0; i<=char_num; i++)
            {
                id_listModel.setProperty(i, "check_state1", isChecked)
            }
        }
        Timer {
                  interval: 500; running: true; repeat: true
                  onTriggered: 
                  {            
                      var all_flag = 1
                      var char_num = maxCharVal - minCharVal
                      for(var i=0; i<=char_num; i++)
                      {
                          if(id_listModel.get(i).check_state1 === false){
                              all_flag = 0
                              break
                          }
                      }
                      id_selectAll.funSetCheckState(all_flag > 0)
                  }
        }
    }
    Component.onCompleted: 
    {
        var char_num = maxCharVal - minCharVal
        for(var i=0; i<=char_num; i++)
        {
            id_listModel.append({"char_val":minCharVal+i, "check_state1":true})
        }
        id_rootItem.width = (char_num+1)*30;
    }
}
