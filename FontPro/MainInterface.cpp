#include "MainInterface.h"

MainInterface::MainInterface(QObject *parent) : QObject(parent)
{
    memset(enableMaskTable, 0xFF, sizeof(enableMaskTable));
    
//    convertAcsii2Hex(0);

}

void MainInterface::setAsciiFlag(int ch, int is_set)
{
    if(ch>=' ' && ch <= 128)
    {
        uint8_t offset = ch/8;
        uint8_t ptr = ch%8;
        if(is_set)
        {
            enableMaskTable[offset] |= 0x01<<ptr;
        }
        else
        {
            enableMaskTable[offset] &= ~(0x01<<ptr);
        }
    }
}

uint8_t MainInterface::takeAsciiFlag(uint8_t ch)
{
    uint8_t flag = 0;
    if(ch <= 128)
    {
        uint8_t offset = ch/8;
        uint8_t ptr = ch%8;
        flag = (enableMaskTable[offset] & 0x01<<ptr) > 0;
    }
//    qDebug("ch=%c, flag=%d", ch, flag);
    return flag;
}

int MainInterface::RGB2Gray(QColor color)
{
    int R = color.red();
    int G = color.green();
    int B = color.blue();
    int grayValue = static_cast<int>(0.299 * R + 0.587 * G + 0.114 * B);
    return grayValue;
}

void MainInterface::convertAcsii2Hex(int font_mx)
{
    if(font_mx<0 || font_mx>=8)
    {
        qDebug("font_mx=%d error!", font_mx);
        emit siqShowMsg("字体倍数有误!");
        return;
    }
    QFile file_save(QString::asprintf("AUTO-T/font_m%d.c", font_mx+1));
    file_save.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file_save);
    QString dev_path = "AUTO-T/develop/";
    QString ds_path = "AUTO-T/ds/";
    
    QString big_path = QString::asprintf("Big Letter/%d倍/", font_mx+1);
    QString small_path = QString::asprintf("Small Letter/%d倍/", font_mx+1);
    QString number_path = QString::asprintf("Number/%d倍/", font_mx+1);
    QString symbol_path = QString::asprintf("Symbol/%d倍/", font_mx+1);
    
    
    QString dev_big_path = dev_path + big_path;
    QString dev_small_path = dev_path + small_path;
    QString dev_number_path = dev_path + number_path;
    QString dev_symbol_path = dev_path + symbol_path;
    
    QString ds_big_path = ds_path + big_path;
    QString ds_small_path = ds_path + small_path;
    QString ds_number_path = ds_path + number_path;
    QString ds_symbol_path = ds_path + symbol_path;
    
    QStringList dev_path_list, ds_path_list;
    dev_path_list.append(dev_number_path);
    dev_path_list.append(dev_big_path);
    dev_path_list.append(dev_small_path);
    dev_path_list.append(dev_symbol_path);
    
    ds_path_list.append(ds_number_path);
    ds_path_list.append(ds_big_path);
    ds_path_list.append(ds_small_path);
    ds_path_list.append(ds_symbol_path);
    
    int path_num = dev_path_list.size();
    //开发稿数组保存
    QString dev_hex_09_str, dev_hex_az_str, dev_hex_AZ_str;
    QString dev_hex_symbol_str01, dev_hex_symbol_str02, dev_hex_symbol_str03, dev_hex_symbol_str04;
    
    //设计稿字宽保存
    QString ds_width_09_str, ds_width_az_str, ds_width_AZ_str;
    QString ds_width_symbol_str01, ds_width_symbol_str02, ds_width_symbol_str03, ds_width_symbol_str04;
    
    for(int m=0; m<path_num; m++)
    {
        QString curr_dev_path = dev_path_list.at(m);//当前开发稿路径
        QString curr_ds_path = ds_path_list.at(m);//当前设计稿路径
        QDir dev_dir(curr_dev_path);
        QDir ds_dir(curr_ds_path);
        QStringList dev_files = dev_dir.entryList(QDir::Files);
        QStringList ds_files = ds_dir.entryList(QDir::Files);
    //            qDebug()<<"dev_files="<<dev_files;
    //            qDebug()<<"ds_files="<<ds_files;
        
        foreach(const QString &file_image, dev_files) 
        {
    //            qDebug() << "File:" << file;  // 输出文件名（不含路径）
            if(!file_image.contains("jpg") && !file_image.contains("JPG"))
            {
                continue;
            }
            QString dev_file_path = curr_dev_path + file_image;
            
    //                qDebug() <<dev_file_path;
            QImage dev_image;
            if(dev_image.load(dev_file_path))
            {
    //                    qDebug("image width=%d, heigh=%d", dev_image.width(), dev_image.height());
                int union_size = dev_image.width()%8 > 0 ? dev_image.width()/8+1 : dev_image.width()/8;//每一行的字节数
               
                QByteArray mask_ba;
                for(int row=0; row<dev_image.height(); row++)//像素转字节数组(一行)
                {
                     uint8_t line_buff[50] = {0};
                    for(int col=0; col<dev_image.width(); col++)
                    {
                        int ptr = col/8;
                        QColor color = dev_image.pixelColor(col, row);
                        int gray = RGB2Gray(color);
    //                        qDebug("row=%d, col=%d, gray=%d", row, col, gray);
                        if(gray < 200)//黑色
                        {
                            int index = col%8;
                            line_buff[ptr] |= 0x80>>index;
                        }
                    }
                    QByteArray union_ba;
                    mask_ba += union_ba.setRawData((char*)line_buff, union_size);//缓存一行
                }
                //保存
                QString hex_str;
                for(int k=0; k<mask_ba.size(); k++)
                {
                    hex_str += QString::asprintf("0x%02X,", (uint8_t)mask_ba.at(k));
                    if((k+1)%16 == 0)//16字节换行
                    {
                        hex_str += "\n";
                    }
                }
                QString file_temp = file_image;
                file_temp = file_temp.remove(".jpg");
                file_temp = file_temp.remove(".JPG");
                uint8_t enable_flag = 0;
                QByteArray file_ba = file_temp.toLocal8Bit();
                if(file_ba.size() == 1)//普通字符
                {
                    uint8_t ch = file_ba.at(0);
    //                        qDebug("ascii=%d", ch);
                    enable_flag = takeAsciiFlag(ch);
                    if(!enable_flag)
                        continue;
                }
    
                if(curr_dev_path == dev_big_path)
                {
                    hex_str += " // "+file_temp+"\n";
                    dev_hex_AZ_str += hex_str;     
                }
                else if(curr_dev_path == dev_small_path)
                {
                    hex_str += " // "+file_temp+"\n";
                    dev_hex_az_str += hex_str;
                }
                else if(curr_dev_path == dev_number_path)
                {
                    hex_str += " // "+file_temp+"\n";
                    dev_hex_09_str += hex_str;
                }
                else
                {    
                    int val = file_temp.toInt();       
                    enable_flag = takeAsciiFlag(val);//特殊字符
                    if(!enable_flag)
                        continue;
                    if(val=='\\')
                    {
                            hex_str += " // "+file_temp+QString::asprintf("  '%c'", val)+"\n";
                    }
                    else
                    {
                        hex_str += " // "+file_temp+QString::asprintf("  %c", val)+"\n";
                    }
                    
                    if(val >= ' ' && val <= '/')
                    {
                        dev_hex_symbol_str01 += hex_str;
                    }
                    else if(val >= ':' && val <= '@')
                    {
                        dev_hex_symbol_str02 += hex_str;
                    }
                    else if(val >= '[' && val <= '`')
                    {
                        dev_hex_symbol_str03 += hex_str;
                    }
                    else if(val >= '{' && val <= '~')
                    {
                        dev_hex_symbol_str04 += hex_str;
                    }        
                }                   
            }//图片转换结束
            else
            {
                qDebug("image load error!");
            }
        }//图片文件夹结束
        
        //设计稿宽度记录
        foreach(const QString &file_image, ds_files) 
        {
            if(!file_image.contains("jpg") && !file_image.contains("JPG"))
            {
                continue;
            }
            QString ds_file_path = curr_ds_path + file_image;
    //                qDebug() <<ds_file_path;
            QString file_temp = file_image;
            file_temp = file_temp.remove(".jpg");
            file_temp = file_temp.remove(".JPG");

            
            QImage ds_image;
            if(ds_image.load(ds_file_path))
            {
                uint8_t enable_flag = 0;
                QByteArray file_ba = file_temp.toLocal8Bit();
                int ds_width = ds_image.width();
                if(file_ba.size() == 1)//普通字符
                {
                    uint8_t ch = file_ba.at(0);
    //                        qDebug("ascii=%d", ch);
                    enable_flag = takeAsciiFlag(ch);
                    if(!enable_flag)
                    {
                        ds_width = 0;
                    }
                }
                
                if(curr_ds_path == ds_big_path)
                {
                    ds_width_AZ_str += QString::asprintf("%d, ", ds_width);
                }
                else if(curr_ds_path == ds_small_path)
                {
                    ds_width_az_str += QString::asprintf("%d, ", ds_width);
                }
                else if(curr_ds_path == ds_number_path)
                {
                    ds_width_09_str += QString::asprintf("%d, ", ds_width);
                }
                else
                {
                    int val = file_temp.toInt();  
                    enable_flag = takeAsciiFlag(val);//特殊字符
                    if(!enable_flag)
                    {
                        ds_width = 0;
                    }
                    if(val >= ' ' && val <= '/')
                    {
                        ds_width_symbol_str01 += QString::asprintf("%d, ", ds_width);
                    }
                    else if(val >= ':' && val <= '@')
                    {
                        ds_width_symbol_str02 += QString::asprintf("%d, ", ds_width);
                    }
                    else if(val >= '[' && val <= '`')
                    {
                        ds_width_symbol_str03 += QString::asprintf("%d, ", ds_width);
                    }
                    else if(val >= '{' && val <= '~')
                    {
                        ds_width_symbol_str04 += QString::asprintf("%d, ", ds_width);
                    }
                } 
            }
            else
            {
                qDebug("image load error!");
            }
        }
    }//当前路径循环结束
    out <<"//Dev Hex Table\n";
    out <<"\n//space to /\n";
    out <<dev_hex_symbol_str01<<"\n";
    out <<"\n//0~9\n";
    out <<dev_hex_09_str<<"\n";
    out <<"\n//: to @\n";
    out <<dev_hex_symbol_str02<<"\n";
    out <<"\n//A~Z\n";
    out <<dev_hex_AZ_str<<"\n";
    out <<"\n//[ to `\n";
    out <<dev_hex_symbol_str03<<"\n";
    out <<"\n//a~z\n";
    out <<dev_hex_az_str<<"\n";
    out <<"\n//{ to ~\n";
    out <<dev_hex_symbol_str04<<"\n";
    out <<"\n\n";
    
    out <<"//Ds Width Table\n";
    out <<ds_width_symbol_str01<<"//space to /\n";
    out <<ds_width_09_str<<"//0~9\n";
    out <<ds_width_symbol_str02<<"//: to @\n";
    out <<ds_width_AZ_str<<"//A~Z\n";
    out <<ds_width_symbol_str03<<"//[ to `\n";
    out <<ds_width_az_str<<"//a~z\n";
    out <<ds_width_symbol_str04<<"//{ to ~\n";
    file_save.close();
    emit siqShowMsg("转换完成!");
}







