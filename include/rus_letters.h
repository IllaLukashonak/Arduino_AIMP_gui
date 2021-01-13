#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

static byte letters[][8]   = {
    { B01110, B10001, B10001, B10001, B11111, B10001, B10001, B00000 },//A
    { B11111, B10000, B10000, B11111, B10001, B10001, B11111, B00000 },//Б
    { B11110, B10001, B10001, B11110, B10001, B10001, B11110, B00000 },//B
    { B11111, B10000, B10000, B10000, B10000, B10000, B10000, B00000 },//Г
    { B01111, B01001, B01001, B01001, B01001, B11111, B10001, B00000 },//Д
    { B11111, B10000, B10000, B11110, B10000, B10000, B11111, B00000 },//Е
    { B10101, B10101, B10101, B01110, B10101, B10101, B10101, B00000 },//Ж
    { B01110, B10001, B00001, B00110, B00001, B10001, B01110, B00000 },//З
    { B10001, B10001, B10011, B10101, B11001, B10001, B10001, B00000 },//И
    { B10101, B10101, B10011, B10101, B11001, B10001, B10001, B00000 },//Й
    { B10001, B10010, B10100, B11000, B10100, B10010, B10001, B00000 },//K
    { B00111, B01001, B10001, B10001, B10001, B10001, B10001, B00000 },//Л
    { B10001, B11011, B10101, B10101, B10001, B10001, B10001, B00000 },//М
    { B10001, B10001, B10001, B11111, B10001, B10001, B10001, B00000 },//Н
    { B01110, B10001, B10001, B10001, B10001, B10001, B01110, B00000 },//О
    { B11111, B10001, B10001, B10001, B10001, B10001, B10001, B00000 },//П
    { B11110, B10001, B10001, B11110, B10000, B10000, B10000, B00000 },//Р
    { B01110, B10001, B10000, B10000, B10000, B10001, B01110, B00000 },//С
    { B11111, B00100, B00100, B00100, B00100, B00100, B00100, B00000 },//Т
    { B10001, B10001, B10001, B01111, B00001, B10001, B01110, B00000 },//У
    { B01110, B10101, B10101, B10101, B01110, B00100, B00100, B00000 },//Ф
    { B10001, B10001, B01010, B00100, B01010, B10001, B10001, B00000 },//Х
    { B10001, B10001, B10001, B10001, B10001, B10001, B11111, B00001 },//Ц
    { B10001, B10001, B10001, B01111, B00001, B00001, B00001, B00000 },//Ч
    { B10101, B10101, B10101, B10101, B10101, B10101, B11111, B00000 },//Ш
    { B10101, B10101, B10101, B10101, B10101, B10101, B11111, B00001 },//Щ
    { B10000, B10000, B10000, B11110, B10001, B10001, B11110, B00000 },//Ь
    { B11000, B01000, B01110, B01001, B01001, B01001, B01110, B00000 },//Ъ
    { B10001, B10001, B10001, B11101, B10101, B10101, B11101, B00000 },//Ы
    { B11110, B00001, B00001, B01111, B00001, B00001, B11110, B00000 },//Э
    { B00000, B00000, B10001, B11011, B10101, B10001, B10001, B00000 },//Ю
    { B01111, B10001, B10001, B01111, B10001, B10001, B10001, B00000 }//Я
};

enum rus_letters {А, Б, В, Г, Д, Е, Ж, З, И, Й, К, Л, М, Н, О, П, Р, С, Т, У, Ф, Х, Ц, Ч, Ш, Щ, Ь, Ъ, Ы, Э, Ю, Я};

void print_with_rus( LiquidCrystal_I2C lcd, String str) {
    for (int i = 0; i < str.length(); ++i){
        if(str[i] < 'А'){
            lcd.print(str);
            return;
        }
        switch (str[i]) {
            case 'А' || 'а': {
                lcd.createChar(0, letters[rus_letters::А]);
                break;
            }
            case 'Б' || 'б': {
                lcd.createChar(0, letters[rus_letters::Б]);
                break;
            }
            case 'В' || 'в': {
                lcd.createChar(0, letters[rus_letters::В]);
                break;
            }
            case 'Г' || 'г': {
                lcd.createChar(0, letters[rus_letters::Г]);
                break;
            }
            case 'Д' || 'д': {
                lcd.createChar(0, letters[rus_letters::Д]);
                break;
            }
            case 'Е' || 'е': {
                lcd.createChar(0, letters[rus_letters::Е]);
                break;
            }
            case 'Ё' || 'ё': {
                lcd.createChar(0, letters[rus_letters::Е]);
                break;
            }
            case 'Ж' || 'ж': {
                lcd.createChar(0, letters[rus_letters::Ж]);
                break;
            }
            case 'З' || 'з': {
                lcd.createChar(0, letters[rus_letters::З]);
                break;
            }
            case 'И' || 'и': {
                lcd.createChar(0, letters[rus_letters::И]);
                break;
            }
            case 'Й' || 'й': {
                lcd.createChar(0, letters[rus_letters::Й]);
                break;
            }
            case 'К' || 'к': {
                lcd.createChar(0, letters[rus_letters::К]);
                break;
            }
            case 'Л' || 'л': {
                lcd.createChar(0, letters[rus_letters::Л]);
                break;
            }
            case 'М' || 'м': {
                lcd.createChar(0, letters[rus_letters::М]);
                break;
            }
            case 'Н' || 'н': {
                lcd.createChar(0, letters[rus_letters::Н]);
                break;
            }
            case 'О' || 'о': {
                lcd.createChar(0, letters[rus_letters::О]);
                break;
            }
            case 'П' || 'п': {
                lcd.createChar(0, letters[rus_letters::П]);
                break;
            }
            case 'Р' || 'р': {
                lcd.createChar(0, letters[rus_letters::Р]);
                break;
            }
            case 'С' || 'с': {
                lcd.createChar(0, letters[rus_letters::С]);
                break;
            }
            case 'Т' || 'т': {
                lcd.createChar(0, letters[rus_letters::Т]);
                break;
            }
            case 'У' || 'у': {
                lcd.createChar(0, letters[rus_letters::У]);
                break;
            }
            case 'Ф' || 'ф': {
                lcd.createChar(0, letters[rus_letters::Ф]);
                break;
            }
            case 'Х' || 'х': {
                lcd.createChar(0, letters[rus_letters::Х]);
                break;
            }
            case 'Ц' || 'ц': {
				lcd.createChar(0, letters[rus_letters::Ц]);
				break;
            }
            case 'Ч' || 'ч': {
	            lcd.createChar(0, letters[rus_letters::Ч]);
	            break;
            }
            case 'Ш' || 'ш': {
	            lcd.createChar(0, letters[rus_letters::Ш]);
	            break;
            }
            case 'Щ' || 'щ': {
	            lcd.createChar(0, letters[rus_letters::Щ]);
	            break;
            }
            case 'Ъ' || 'ъ': {
	            lcd.createChar(0, letters[rus_letters::Ъ]);
	            break;
            }
            case 'Ь' || 'ь': {
	            lcd.createChar(0, letters[rus_letters::Ь]);
	            break;
            }
            case 'Ы' || 'ы': {
	            lcd.createChar(0, letters[rus_letters::Ы]);
	            break;
            }
            case 'Э' || 'э': {
	            lcd.createChar(0, letters[rus_letters::Э]);
	            break;
            }
            case 'Ю' || 'ю': {
	            lcd.createChar(0, letters[rus_letters::Ю]);
	            break;
            }
            case 'Я' || 'я': {
	            lcd.createChar(0, letters[rus_letters::Я]);
	            break;
            } 
        }
        lcd.write(byte(0));
    }
}