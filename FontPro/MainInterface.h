#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QObject>
#include<QImage>
#include<QPixmap>
#include<QDir>
#include<QDebug>
#include<QByteArray>
#include<iostream>

class MainInterface : public QObject
{
    Q_OBJECT
public:
    explicit MainInterface(QObject *parent = nullptr);
    int RGB2Gray(QColor color);
    
   Q_INVOKABLE  void setAsciiFlag(int ch, int is_set);
    uint8_t takeAsciiFlag(uint8_t ch);
   Q_INVOKABLE  void convertAcsii2Hex(int font_mx);
    
private:
    uint8_t enableMaskTable[20];
signals:
    void siqShowMsg(QString msg);
};

#endif // MAININTERFACE_H
