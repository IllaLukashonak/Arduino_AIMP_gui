#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Thread.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Указываем I2C адрес (наиболее распространенное значение), а также параметры экрана (в случае LCD 1602 - 2 строки по 16 символов в каждой

Thread reading_thread = Thread();
Thread scroll_thread = Thread();

bool flag_artist = false;
bool flag_title = false;

void transmit();
void autoscroll();

void setup()
{

    reading_thread.onRun(transmit);
    reading_thread.setInterval(500);

    scroll_thread.onRun(autoscroll);
    scroll_thread.setInterval(300);

    Serial.begin(9600);
    Serial.println("Start!");
    lcd.init();                      // Инициализация дисплея
    lcd.backlight();                 // Подключение подсветки
    lcd.setCursor(0, 0);             // Установка курсора в начало первой строки
    lcd.print("Hello");              // Набор текста на первой строке
    lcd.setCursor(0, 1);             // Установка курсора в начало второй строки
    lcd.print("Proged by LIS");
    
}
void loop()
{
    if (reading_thread.shouldRun()) {
        reading_thread.run();
    }
    if (scroll_thread.shouldRun()) {
        scroll_thread.run();
    }
}

void transmit() {
    if (!(Serial.available() > 0))
    {
        return;
    }

    lcd.clear();

    String* artist = new String;
    String* title = new String;

    if (Serial.readStringUntil('|') == "start_trans")
    {
        Serial.println("Start reading");
        *artist = Serial.readStringUntil('|');
        *title = Serial.readStringUntil('|');

        if (artist->length() > 16) {
            flag_artist = true;
        }
        else {
            flag_artist = false;
        }
        if (title->length() > 16)
        {
            flag_title = true;
        }
        else
        {
            flag_title = false;
        }

        if (artist->length() > 40)
        {
                *artist = artist->substring(0, 39);
        }
        if (title->length() > 40)
        {
                *title = title->substring(0, 39);
        }

        Serial.println("Stop reading");
        Serial.println(*artist);
        Serial.println(*title);
        lcd.setCursor(0, 0);
        lcd.print(*artist);
        lcd.setCursor(0, 1);
        lcd.print(*title);
    }

    delete artist;
    delete title;
}
void autoscroll()
{
    if (flag_artist || flag_title) {
        lcd.scrollDisplayLeft();
    }
}