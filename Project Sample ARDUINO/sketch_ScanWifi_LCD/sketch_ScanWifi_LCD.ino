#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ESP8266WiFi.h"
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  //Serial.println("hello Jo");
  lcd.println("Setup done");
  delay(1000);
  lcd.clear();
}
 
void loop() {

 
  lcd.println("scan start");
 
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  delay(500);
  lcd.clear();
  lcd.println("scan done");
  delay(2000);
  lcd.clear();
  if (n == 0)
    lcd.println("not found");
  else
  {
    lcd.print(n);
    lcd.println(" networks");
    delay(2000);
    lcd.clear();
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      lcd.print(i + 1);
      lcd.print(": ");
      lcd.print(WiFi.SSID(i));
      delay(2000);
      lcd.clear();
    }
  }
  lcd.clear();
 
  // Wait a bit before scanning again
  delay(3000);
}
