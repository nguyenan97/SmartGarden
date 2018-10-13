#include <ESP8266WiFi.h>
const char WiFiPassword[] = "12345678";
const char AP_NameChar[] = "nhom1" ;

WiFiServer server(80);
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body {font-size:140%;} #main {display: table; margin: auto;  padding: 0 10px 0 10px; } h2,{text-align:center; } .button { padding:10px 10px 10px 10px; width:100%;  background-color: #4CAF50; font-size: 120%;}</style><title>LED Control</title></head><body><div id='main'><h2>LED Control</h2>";
String html_2 = "<form id='F1' action='LEDON1'><input class='button' type='submit' value='LED ON1' ></form><br>";
String html_3 = "<form id='F2' action='LEDOFF1'><input class='button' type='submit' value='LED OFF1' ></form><br>";
String html_4 = "<form id='F3' action='LEDON2'><input class='button' type='submit' value='LED ON2' ></form><br>";
String html_5 = "<form id='F4' action='LEDOFF2'><input class='button' type='submit' value='LED OFF2' ></form><br>";
String html_6 = "</div></body></html>";

String request = "";
int LED_Pin1 = D6;
int LED_Pin2 = D7;

void setup() 
{
    pinMode(LED_Pin1, OUTPUT);
    pinMode(LED_Pin2, OUTPUT); 
    
    boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
    server.begin();
   
} // void setup()



void loop() 
{

    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client)  {  return;  }
    
    // Read the first line of the request
    request = client.readStringUntil('\r');
    
    if       ( request.indexOf("LEDON1") > 0 )  { digitalWrite(LED_Pin1, HIGH); }
    else if  ( request.indexOf("LEDOFF1") > 0 ) { digitalWrite(LED_Pin1, LOW);   }
     if       ( request.indexOf("LEDON2") > 0 )  { digitalWrite(LED_Pin2, HIGH);  }
    else if  ( request.indexOf("LEDOFF2") > 0 ) { digitalWrite(LED_Pin2, LOW);   }

    client.flush();
    
    client.print( header );
    client.print( html_1 );
    client.print( html_2 );
    client.print( html_3 );
    client.print( html_4);
    client.print( html_5 );
    client.print( html_6);
    
    delay(5);
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
  
}
