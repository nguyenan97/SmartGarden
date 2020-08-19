#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
//0x27 là địa chỉ màn hình trong bus I2C. Phần này chúng ta không cần phải quá bận tâm vì hầu hết màn hình (20x4,...) đều như thế này!
//16 là số cột của màn hình (nếu dùng loại màn hình 20x4) thì thay bằng 20
//2 là số dòng của màn hình (nếu dùng loại màn hình 20x4) thì thay bằng 4
void setup() {
  lcd.init();       //Khởi động màn hình. Bắt đầu cho phép Arduino sử dụng màn hình, cũng giống như dht.begin() trong chương trình trên
  lcd.backlight();   //Bật đèn nền
  lcd.print("Hello JO");  //Xuất ra chữ Hello world, mặc định sau khi init thì con trỏ tại cột 0 hàng 0 (trong C, khác với quy ước của tiếng Việt, mọi chỉ số đều bắt đầu bằng số 0, vì vậy bạn cần hiểu rằng, nếu ta kẻ một bảng có 2 hàng và 16 cột thì ô góc trên cùng bên trái là ô (0,0) tương tự với các ô khác, ta cứ tăng dần giá trị lên!
  lcd.setCursor(0,1); //Đưa con trỏ tới hàng 1, cột 0
  lcd.print("I love Arduino !");// Bạn thấy trên màn hình rồi chứ?
}
void loop() {
}
