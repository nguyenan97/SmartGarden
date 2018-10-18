#include <DHT.h>   
#include <ESP8266WiFi.h>

// CAM BIEN NHIET DO DO AM
#define DHTPIN D4      
#define DHTTYPE DHT21   
DHT dht(DHTPIN, DHTTYPE);

//CAM BIEN DAT
int const SENSOR_MH_D_PIN = D5;
int const SENSOR_MH_A_PIN = A0;
int const TIME_TO_GET_SAMPLE = 5000;
int const SAMPLE_TIME =500; 
int const TREE_WATER_LEVEL_HIGH = 600;
int const TREE_WATER_LEVEL_LOW = 300;
int bumpStatus = 0;
int waterStatus = 0;// -1: less water, 0: enough water,  +1 : more water



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
        
        //CAM BIEN NHIET DO DO AM
        dht.begin();
        Serial.print("Connecting");
        
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {    // Không kết nối được với internet thì lặp dấu .
                Serial.print(".");
                delay(100);
        }
        
        // CAM BIEN DAT
        pinMode(SENSOR_MH_D_PIN,INPUT); 

        // ANH SANG
        //pinMode(AS_D_PIN,INPUT);
        
        Serial.println("\r\nWiFi connected");
}
void loop() {
        // wait and then post again
        delay(postingInterval);
         // CAM BIEN DAT
        wateringProcess();
        showLedInfo();
        int valueDat = getSensorSampleValue();

        //CAM BIEN NHIET DO DO AM
        float valueTemp = dht.readTemperature();  // Đọc nhiệt độ
        float valueHumi = dht.readHumidity();       // Đọc độ ẩm
        if (valueTemp < 32) {
                Serial.println("FAN_RELAY 0");      
        }
        else{
                Serial.println("FAN_RELAY 1");  
          
        }        
        if (client.connect(server, 80)) {
                // Construct API request body
                String body = "field1=" + String(valueTemp, 1) + "&field2=" + String(valueHumi, 1)+ "&field3=" + String(valueDat);
               // String body = "field1=" + String(valueDat);
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
                Serial.printf("Nhiet do dat %s - %s - %s  \r\n", String(valueTemp,1).c_str(),String(valueHumi,1).c_str(),String(valueDat).c_str());
                
        }
        client.stop();
}

//HAM
void wateringProcess(){
  int sensorStatus = digitalRead(SENSOR_MH_D_PIN);
  int sensorValue = getSensorSampleValue();
  if(sensorStatus == 0){
    if(sensorValue > TREE_WATER_LEVEL_HIGH){
      //digitalWrite(T_RELAY_PIN, HIGH);
      Serial.println("T_RELAY_PIN 1");
      bumpStatus = 1;
      waterStatus = -1;
      //Serial.println(sensorValue);
    }else if(sensorValue < TREE_WATER_LEVEL_LOW){
     // digitalWrite(T_RELAY_PIN, LOW);
     Serial.println("T_RELAY_PIN 0");
      bumpStatus = 0;
      waterStatus = +1;
     // Serial.println(sensorValue);
    }else{
     // digitalWrite(T_RELAY_PIN, LOW);
     Serial.println("T_RELAY_PIN 0");
      bumpStatus = 0;
      waterStatus = 0;
      //Serial.println(sensorValue);
    }
  }else{
    //digitalWrite(T_RELAY_PIN, HIGH);
    Serial.println("T_RELAY_PIN 1");
      bumpStatus = 1;
      waterStatus = -1;
     // Serial.println(sensorValue);
  }
}
int getSensorSampleValue(){
  int value = 0;
  int t = TIME_TO_GET_SAMPLE/ SAMPLE_TIME;
  int total = 0;
  for(int i =0; i < t ; i++){
    total += analogRead(SENSOR_MH_A_PIN);
    delay(t);
  }
  return total / t;
}
void showLedInfo(){
  if(bumpStatus == 1){
    //digitalWrite(LED_YEWLOW_PIN, HIGH);
    Serial.println("LED_YEWLOW_PIN 1");
  }else{
    //digitalWrite(LED_YEWLOW_PIN, LOW);
    Serial.println("LED_YEWLOW_PIN 0");
  }

  if(waterStatus == 0){
   // digitalWrite(LED_RED_PIN, LOW);
   // digitalWrite(LED_BLUE_PIN, HIGH);
    Serial.println("LED_RED_PIN 0");
    Serial.println("LED_BLUE_PIN 1");
  }else{
   // digitalWrite(LED_RED_PIN, HIGH);
   // digitalWrite(LED_BLUE_PIN,LOW);
    Serial.println("LED_RED_PIN 1");
    Serial.println("LED_BLUE_PIN 0");
  }
}
 
