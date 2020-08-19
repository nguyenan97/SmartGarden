#include <AFMotor.h>
 
AF_DCMotor motor1(1, MOTOR12_64KHZ); // tạo động cơ #2, 64KHz pwm  
AF_DCMotor motor2(2, MOTOR12_64KHZ); 
void setup() {  
    
    Serial.begin(9600);           // mở cổng Serial monitor 9600 bps 
    
    Serial.println("Hello my racing");     
    
    motor1.setSpeed(255);     // chọn tốc độ maximum 255`/255
    motor2.setSpeed(255);
}  
 
void loop() {  
 
    Serial.print("tien");     
    
    motor1.run(FORWARD);      // động cơ tiến 
    motor2.run(FORWARD);
    delay(1000);    
    
    Serial.print("lui");  
    
    motor1.run(BACKWARD);     // động cơ lùi  
    motor2.run(BACKWARD);
    delay(1000);     
    
    Serial.print("tack");  
    
    motor1.run(RELEASE);      //   dừng động cơ
    motor2.run(RELEASE);
    delay(1000);
 
}
