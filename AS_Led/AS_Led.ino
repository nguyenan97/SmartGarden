int cambien = 2;// khai báo chân digital 10 cho cảm biến
int Led = 3;//kháo báo chân digital 8 cho đèn LED
void setup (){
pinMode(Led,OUTPUT);//pinMode xuất tín hiệu đầu ra cho led
pinMode(cambien,INPUT);//pinMode nhận tín hiệu đầu vào cho cảm biê
      Serial.begin(9600);// Khởi động Serial ở baudrate 9600
}

void loop (){
int value = digitalRead(cambien);//lưu giá trị cảm biến vào biến value

if(value==1)
{
  digitalWrite(Led,HIGH);//xuất giá trị ra đèn LED
  }
  else
  {
    digitalWrite(Led,LOW);//xuất giá trị ra đèn LED
    }
Serial.println(value); // sang: 0
}
