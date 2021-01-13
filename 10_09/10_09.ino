#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Указываем I2C адрес (наиболее распространенное значение), а также параметры экрана (в случае LCD 1602 - 2 строки по 16 символов в каждой

char text[128] = "\0";
bool flag = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start!");
  lcd.init();                      // Инициализация дисплея
  lcd.backlight();                 // Подключение подсветки
  lcd.setCursor(0, 0);             // Установка курсора в начало первой строки
  lcd.print("Hello");              // Набор текста на первой строке
  lcd.setCursor(0, 1);             // Установка курсора в начало второй строки
  lcd.print("ŁIS");                // Набор текста на второй строке
  
}
void loop()
{
  delay(1000);
  for (int i = 0; Serial.available() > 0; i++) { //если есть доступные данные
    // считываем байт
    text[i] = (char)Serial.read();
  }
  if (text[0] != '\0' || flag == false) {//Если что-то считали
    flag = true;
    Serial.println (text);
    lcd.setCursor(0, 0);
    for(int i = 0; i < 16; i++){//Очищаем строку 0
      lcd.print(' ');
    }
    lcd.setCursor(0, 0);
    for (int i = 0; i < 128; i++){//Заполняем строку 0
      if (text[i] != '\0') {
        lcd.print(text[i]);
      }
      else {
        break;
      }
    }
  }
  else if (text[0] != '\0' || flag == true) {
    flag = false;
    Serial.println (text);
    lcd.setCursor(1, 0);
    for(int i = 0; i < 16; i++){//Очищаем строку 1
      lcd.print(' ');
    }
    lcd.setCursor(1, 0);
    for (int i = 0; i < 128; i++){//Заполняем строку 1
      if (text[i] != '\0') {
        lcd.print(text[i]);
      }
      else {
        break;
      }
    }
  }
  for (int i = 0; i < 128; i++) {//заполняем буфер мусором
    text[i] = '\0';
  }

// when characters arrive over the serial port...
//  if (Serial.available()) {
//    // wait a bit for the entire message to arrive
//    delay(100);
//    // clear the screen
//    lcd.clear();
//    // read all the available characters
//    while (Serial.available() > 0) {
//      // display each character to the LCD
//      lcd.write(Serial.read());
//    }
//  }
}
