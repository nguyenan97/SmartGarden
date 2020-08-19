void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.write(64); // send a byte with the value 45
 int bytesSent = Serial.write("hello"); //send the string "hello" and return the length of the string.
delay(3000);
}
