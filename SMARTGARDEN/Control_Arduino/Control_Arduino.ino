#include <SerialCommand.h> 
SerialCommand sCmd; 
int red = 2;
int yewlow = 4;
int blue = 6;
int replay = 8; // may bom
int FanRelay = 10;

void setup() {
  Serial.begin(115200);
  pinMode(red,OUTPUT);
  pinMode(yewlow,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(replay,OUTPUT);
  pinMode(FanRelay,OUTPUT);
  sCmd.addCommand("LED_RED_PIN",   led_red); 
  sCmd.addCommand("LED_YEWLOW_PIN",   led_yewlow); 
  sCmd.addCommand("LED_BLUE_PIN",   led_blue); 
  sCmd.addCommand("T_RELAY_PIN",   led_replay);   
  sCmd.addCommand("FAN_RELAY",   replayFan); 
}
 
void loop() {
  sCmd.readSerial();
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
