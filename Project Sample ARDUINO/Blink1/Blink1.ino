/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
int pin=13;
int pin12=12;
int time=500;
int time1=0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin, OUTPUT);
  pinMode(pin12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (time == 500)
    {
      time = 100;
      time1=500;
    }
      else
      {
      time = 500;
      time1=100;
      }
  for(int i=0;i<5;i++)
  {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time);                       // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(time);
  }// wait for a second
  digitalWrite(pin, LOW); 
  for(int j=0;j<5;j++)
  {
  digitalWrite(pin12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(pin12, LOW);    // turn the LED off by making the voltage LOW
  delay(time1);
  }// wait for a second
  digitalWrite(pin12, LOW); 
}
