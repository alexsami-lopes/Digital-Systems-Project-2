#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>

#define NUM 22
//USE WIRINGPI PIN NUMBERS
#define LCD_RS  13               //Register select pin
#define LCD_E   18               //Enable Pin
#define LCD_D4  21               //Data pin 4
#define LCD_D5  24               //Data pin 5
#define LCD_D6  26               //Data pin 6
#define LCD_D7  27               //Data pin 7

int display = 0;

int main (void)
{
   wiringPiSetup();
   display = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
   lcdPuts(display, "Funcionando");
   return 0;

}
