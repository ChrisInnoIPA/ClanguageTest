#include <EEPROM.h> 

#define EEPROM_write(address, p) {int i = 0; byte *pp = (byte*)&(p);
for(; i < sizeof(p); i++) EEPROM.write(address+i, pp[i]);} #define EEPROM_read(address, p) 
{int i = 0; byte *pp = (byte*)&(p);
for(; i < sizeof(p); i++) pp[i]=EEPROM.read(address+i);} 
unsigned long incomingByte = 0; // 定義無符號長整數型變量incomingByte初始值為0 void setup() { Serial.begin(9600); // 打開串口，設置數據傳輸速率9600 } void loop() { if (Serial.available() > 0) { incomingByte = Serial.parseInt(); //讀取串口傳入的下一個有效整數，把該整數賦值給incomingByte變量 EEPROM_write(0,incomingByte) //把incomingByte變量從0地址位開始寫入EEPROM } EEPROM_read(0,incomingByte) //從0地址位開始讀取EEPROM，把值寫入變量incomingByte Serial.println(incomingByte); //通過串口輸出 delay(1000); }

