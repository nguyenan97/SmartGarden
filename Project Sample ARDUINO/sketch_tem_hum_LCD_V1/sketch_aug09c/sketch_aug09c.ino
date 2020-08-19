#include <Wire.h>
//#include <LCD.h>
#include <LiquidCrystal_I2C.h>

/* YourDuino.com Example Software Sketch
   DHT11 Humidity and Temperature Sensor test
   Credits: Rob Tillaart
   http://arduino-direct.com/sunshop/index.php?l=product_detail&p=162
   terry@yourduino.com */
   
/*-----( Import needed libraries )-----*/
#include <dht11.h>

/*-----( Declare objects )-----*/
dht11 DHT11;
LiquidCrystal_I2C lcd(0x3F,16,2);

/*-----( Declare Constants, Pin Numbers )-----*/
#define DHT11PIN 2



void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  lcd.backlight();
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("DHT11 TEST PROGRAM ");
  lcd.setCursor(0,1);
  lcd.print("LIBRARY VERSION: ");
  lcd.setCursor(0,2);
  lcd.print(DHT11LIB_VERSION);
  delay(2000);
  lcd.clear();
}/*--(end setup )---*/
  //lcd.setCursor(3,0);
  
void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  //lcd.print("\n");

  int chk = DHT11.read(DHT11PIN);
  lcd.setCursor(0,0);
  lcd.print("Read sensor: ");
  switch (chk)
  {
    case 0: lcd.print("OK"); break;
    case -1: lcd.print("Checksum error"); break;
    case -2: lcd.print("Time out error"); break;
    default: lcd.print("Unknown error"); break;
  }
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print((float)DHT11.humidity, 2);
  
  lcd.setCursor(0,2);
  lcd.print("Temperature: ");
  lcd.print((float)DHT11.temperature, 2);
  
  //lcd.print("Temperature (oF): ");
  //lcd.println(Fahrenheit(DHT11.temperature), 2);

  //lcd.print("Temperature (K): ");
  //lcd.println(Kelvin(DHT11.temperature), 2);
  
  lcd.setCursor(0,3);
  lcd.print("Dew Point: ");
  lcd.print(dewPoint(DHT11.temperature, DHT11.humidity));
  
  //lcd.print("Dew PointFast (oC): ");
  //lcd.println(dewPointFast(DHT11.temperature, DHT11.humidity));

  delay(2000);
}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/
//
//Celsius to Fahrenheit conversion
double Fahrenheit(double celsius)
{
        return 1.8 * celsius + 32;
}

//Celsius to Kelvin conversion
double Kelvin(double celsius)
{
        return celsius + 273.15;
}

// dewPoint function NOAA
// reference: http://wahiduddin.net/calc/density_algorithms.htm 
double dewPoint(double celsius, double humidity)
{
        double A0= 373.15/(273.15 + celsius);
        double SUM = -7.90298 * (A0-1);
        SUM += 5.02808 * log10(A0);
        SUM += -1.3816e-7 * (pow(10, (11.344*(1-1/A0)))-1) ;
        SUM += 8.1328e-3 * (pow(10,(-3.49149*(A0-1)))-1) ;
        SUM += log10(1013.246);
        double VP = pow(10, SUM-3) * humidity;
        double T = log(VP/0.61078);   // temp var
        return (241.88 * T) / (17.558-T);
}

// delta max = 0.6544 wrt dewPoint()
// 5x faster than dewPoint()
// reference: http://en.wikipedia.org/wiki/Dew_point
double dewPointFast(double celsius, double humidity)
{
        double a = 17.271;
        double b = 237.7;
        double temp = (a * celsius) / (b + celsius) + log(humidity/100);
        double Td = (b * temp) / (a - temp);
        return Td;
}

/* ( THE END ) */

