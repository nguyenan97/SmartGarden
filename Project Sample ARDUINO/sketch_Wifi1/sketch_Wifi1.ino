#include <Wifi.h>
//void setup() {
  // put your setup code here, to run once:
 char ssid[]="HuyMinh";
 char password[] ="josephus1964"; 
//}
Wifi.begin(ssid,password);
//void loop() {
  // put your main code here, to run repeatedly:
while (Wifi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("Wifi connected");
//print the IP address
Serial.println(Wifi.localIP());
//}
