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


void clearDisplay(){
	digitalWrite(LCD_E, HIGH);

	digitalWrite(LCD_RS, LOW);
	digitalWrite(LCD_D4, LOW);
	digitalWrite(LCD_D5, LOW);
	digitalWrite(LCD_D6, LOW);
	digitalWrite(LCD_D7, LOW);

	digitalWrite(LCD_E, LOW);
	delay(1);
	digitalWrite(LCD_E, HIGH);
	delay(1);
	digitalWrite(LCD_E, LOW);
	

	digitalWrite(LCD_D4, HIGH);
	digitalWrite(LCD_E, LOW);
	delay(1);
	digitalWrite(LCD_E, HIGH);

	delay(1);
    digitalWrite(LCD_E, LOW);
}


int lcd = 0;

int main (void)
{
	wiringPiSetup();
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);

//	clearDisplay();
	pinMode(NUM, OUTPUT);
	for(;;){
//		clearDisplay();
		digitalWrite(NUM, HIGH);
		delay(1000);
		digitalWrite(NUM, LOW);
		delay(1000);	
        lcdPosition(lcd, 0, 0);
        lcdPuts(lcd, "10/04/2023!!!!");
        delay(1000);
        //lcdClear(lcd);
        delay(1000);
	}
	return 0;
}
