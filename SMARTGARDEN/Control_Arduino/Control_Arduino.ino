#include <SerialCommand.h> 
SerialCommand sCmd; 
int red = 2;
int yewlow = 4;
int blue = 6;
int replay = 8; // may bom
int FanRelay = 10;
int quangTro = 12;
int ledQuangTro = 13;
void setup() {
  Serial.begin(115200);
  pinMode(red,OUTPUT);
  pinMode(yewlow,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(replay,OUTPUT);
  pinMode(FanRelay,OUTPUT);
  pinMode(quangTro,INPUT);
  pinMode(ledQuangTro,OUTPUT);
  sCmd.addCommand("RED_LED",   led_red); 
  sCmd.addCommand("YEWLOW_LED",   led_yewlow); 
  sCmd.addCommand("BLUE_LED",   led_blue); 
  sCmd.addCommand("BOM_REPLAY",   led_replay);   
  sCmd.addCommand("QUAT_REPLAY",   replayFan); 
}
 
void loop() {
  sCmd.readSerial();
  int gtQuangTro = digitalRead(quangTro);
  digitalWrite(ledQuangTro, gtQuangTro);
}
 

void led_red() {
  
  char *arg;
  arg = sCmd.next();
  
  int value = atoi(arg); 
  digitalWrite(red,value);
}

 void led_yewlow() {
  
  char *arg;
  arg = sCmd.next();
  
  int value = atoi(arg); 
  digitalWrite(yewlow,value);
}

 void led_blue() {
  
  char *arg;
  arg = sCmd.next();
  
  int value = atoi(arg); 
  digitalWrite(blue,value);
}

 void led_replay() {
  
  char *arg;
  arg = sCmd.next();
  
  int value = atoi(arg); 
  digitalWrite(replay,value);
}

 void replayFan() {
  
  char *arg;
  arg = sCmd.next();
  
  int value = atoi(arg); 
  digitalWrite(FanRelay,value);
}
