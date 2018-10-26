#include <DHT.h>   
#include <ESP8266WiFi.h>

// DHT 21
#define DHTPIN D4      
#define DHTTYPE DHT21   
DHT dht(DHTPIN, DHTTYPE);

//CAM BIEN DAT
#define DATPINA0 A0
//#define DATPIND0 D3

//cam bien anh sang
//#define QUANGTROPIN D7

// Wi-Fi Settings
const char* ssid = "An Phong 2"; 
const char* password = "@Nnguyen123"; 
WiFiClient client;
// ThingSpeak Settings
const int channelID = 571966; // ID thingspeak
String writeAPIKey = "HQV8EHXS2UC3LRUV"; // write API key for your ThingSpeak Channel
const char* server = "api.thingspeak.com";
const int postingInterval = 2000; // post data every 2 seconds

void setup() {
        Serial.begin(115200);
        pinMode(DATPINA0, INPUT); 
        //pinMode(DATPIND0, INPUT);
 //       pinMode(QUANGTROPIN, INPUT); 
        dht.begin();
        Serial.print("Connecting");
        
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {    // Không kết nối được với internet thì lặp dấu .
                Serial.print(".");
                delay(100);
        }
        Serial.println("\r\nWiFi connected");
}

void RunBom(float amdat)
{
 if(amdat > 550)
   {
      Serial.println("BOM_REPLAY 1");
      Serial.println("RED_LED 1");
      Serial.println("YEWLOW_LED 1");
      Serial.println("BLUE_LED 0");
        //digitalWrite(PUMPPIN, HIGH);
    }
       
   else
   {
      Serial.println("BOM_REPLAY 0");
      Serial.println("RED_LED 0");
      Serial.println("YEWLOW_LED 0");
      Serial.println("BLUE_LED 1");
        //digitalWrite(PUMPPIN,LOW);
    
    }

  
}
void RunQuat(float nhiet)
{
   if(nhiet > 29)
         Serial.println("QUAT_REPLAY 1");
        
   else
        Serial.println("QUAT_REPLAY 0");
  
}
void loop() {
    delay(1000);
    float doAmDat = analogRead(DATPINA0);
   // int quangTro = digitalRead(QUANGTROPIN);
  
    float temp = dht.readTemperature();
    float humi = dht.readHumidity();
    if (isnan(temp) || isnan(humi)|| isnan(doAmDat)  ) {
                Serial.println("Failed to read from DHT sensor!");
                return;
    }
    if (client.connect(server, 80)) {
                // Construct API request body
                String body = "field1=" + String(temp, 1) + "&field2=" + String(humi, 1) + "&field3=" + String(doAmDat, 1);
                
                client.print("POST /update HTTP/1.1\n");
                client.print("Host: api.thingspeak.com\n");
                client.print("Connection: close\n");
                client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
                client.print("Content-Type: application/x-www-form-urlencoded\n");
                client.print("Content-Length: ");
                client.print(body.length());
                client.print("\n\n");
                client.print(body);
                client.print("\n\n");
                //Serial.printf("Nhiet do %s - Do am %s Do am dat %s\r\n", String(temp, 1).c_str(), String(humi, 1).c_str(),String(doAmDat, 1).c_str());

        }
        client.stop();
  RunBom(doAmDat);
  RunQuat(temp);
        
  
        
   /*if(quangTro != 0)
         Serial.println("DEN_LED 1");
        
   else
        Serial.println("DEN_LED 0");
    */   
    delay(1000); 
}
