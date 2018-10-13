int rainSensor = 6;
void setup() {
  pinMode (7, OUTPUT);
  pinMode(rainSensor,INPUT);
  Serial.begin(9600);
  Serial.println("Da khoi dong xong");
}
void loop() {
  int value = digitalRead(rainSensor);
  if (value == HIGH)
 { 
      Serial.println("Dang khong mua");
      digitalWrite (7, LOW);
  } 
  else 
  {
      digitalWrite (7, HIGH);
      Serial.println("Dang mua");
  }
  delay(1000);
 }
