#include <wiringPi.h>
#include <lcd.h>
#include <unistd.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  13               //Register select pin
#define LCD_E   18               //Enable Pin
#define LCD_D4  21               //Data pin 4
#define LCD_D5  24               //Data pin 5
#define LCD_D6  26               //Data pin 6
#define LCD_D7  27               //Data pin 7

int main()
{
    int lcd;
    wiringPiSetup();
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

    while(1){
        lcdPosition(lcd, 0, 0);
        lcdPuts(lcd, "Hello, world!");
        sleep(2);
        lcdClear(lcd);
        sleep(2);
        }
}
