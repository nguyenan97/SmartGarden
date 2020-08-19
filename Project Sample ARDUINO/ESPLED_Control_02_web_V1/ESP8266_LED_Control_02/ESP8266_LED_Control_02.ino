/*
 * Sketch: ESP8266_LED_Control_02
 * Control an LED from a web browser
 * Intended to be run on an ESP8266
 * 
 * connect to the ESP8266 AP then
 * use web broswer to go to 192.168.4.1
 * 
 */


#include <ESP8266WiFi.h>
const char WiFiPassword[] = "12345678";
const char AP_NameChar[] = "THAI" ;

WiFiServer server(80);



String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body {font-size:140%;} #main {display: table; margin: auto;  padding: 0 10px 0 10px; } h2,{text-align:center; } .button { padding:10px 10px 10px 10px; width:100%;  background-color: #4CAF50; font-size: 120%;}</style><title>LED Control</title></head><body><div id='main'><h2>LED Control</h2>";
String html_2 = "<form id='F1' action='LEDON'><input class='button' type='submit' value='LED ON' ></form><br>";
String html_3 = "<form id='F2' action='LEDOFF'><input class='button' type='submit' value='LED OFF' ></form><br>";
String html_4 = "</div></body></html>";

String request = "";
int LED_Pin = D1;

void setup() 
{
    pinMode(LED_Pin, OUTPUT); 
    
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
    
    if       ( request.indexOf("LEDON") > 0 )  { digitalWrite(LED_Pin, HIGH);  }
    else if  ( request.indexOf("LEDOFF") > 0 ) { digitalWrite(LED_Pin, LOW);   }

    client.flush();
    
    client.print( header );
    client.print( html_1 );
    client.print( html_2 );
    client.print( html_3 );
    client.print( html_4);
    
    delay(5);
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
  
} // void loop() 












  
