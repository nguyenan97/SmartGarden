#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("joseph-igo", "josephus1964");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
