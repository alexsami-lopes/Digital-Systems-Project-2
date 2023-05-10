#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>


#define LCD_RS  13               //Register select pin (RS)
#define LCD_E   18               //Enable Pin
#define LCD_D4  21               //DB4
#define LCD_D5  24               //DB5
#define LCD_D6  26               //DB6
#define LCD_D7  27               //DB7

#define BUTTON_NEXT  23          // PA07
#define BUTTON_PREVIOUS  25      // PA10
#define BUTTON_ENTER  19         // PA20

const signed short lcdHandle = 0;

void scrollTextRightToLeft(void);
void scrollTextLeftToRight(void)

char message[] = "Inicializando...";
int count = 0;
int j = 0;
int lcd;
char scrollPaddingDefault[] = "                ";
char scrollPadding[] = "                ";
int menuPos = 0;

char arrowLeftBig[8] = { 
	0b00001,
	0b00011,
	0b00111,
	0b01111,
	0b01111,
	0b00111,
	0b00011,
	0b00001
};

char arrowLeftSmall[8] = { 
    0b00000,
	0b00001,
	0b00011,
	0b00111,
	0b00111,
	0b00011,
	0b00001,
	0b00000
};

char arrowRightBig[8] = 
{ 
    0b10000,
	0b11000,
	0b11100,
	0b11110,
	0b11110,
	0b11100,
	0b11000,
	0b10000
};
char arrowRightSmall[8] = 
{
    0b00000,
	0b10000,
	0b11000,
	0b11100,
	0b11100,
	0b11000,
	0b10000,
	0b00000
};


void scrollTextRightToLeft(int mLength, int pos)
{
        int i, n;
        int h;
        int tempSpace = 0;
        int messageLength = 0;
        if (mLength == 0)
            messageLength = strlen(scrollPadding) + strlen(message);
        else
            messageLength = mLength;
        for (n = 0; n < messageLength; n++){
            h = mLength; 
            usleep(100000); 
            printf("\x1B[2J"); 
            if (j > messageLength)
                j = 0;

            for (i = pos; i < j ; i++){
                scrollPadding[h - j] = message[i];
                h++;
                }
            //lcdPosition(lcd, 0, 0);
            //lcdClear(lcd);
            lcdPrintf(lcd, "%s", scrollPadding);
            j++;
        }
}
void scrollTextLeftToRight(int mLength, int pos)
{
        int i, n;
        int h;
        int tempSpace = 0;
        int messageLength = 0;
        if (mLength == 0)
            messageLength = strlen(scrollPadding) + strlen(message);
        else
            messageLength = mLength;
        for (n = 0; n < messageLength; n++){
            h = mLength; 
            usleep(100000); 
            printf("\x1B[2J"); 
            if (j > messageLength)
                j = 0;

            for (i = pos; i >= (strlen(message) - mLength); i--){
                scrollPadding[j - h] = message[i];
                h++;
                }
            //lcdPosition(lcd, 0, 0);
            //lcdClear(lcd);
            lcdPrintf(lcd, "%s", scrollPadding);
            j++;
        }
}

void initialization(void)
{
    message[] = "Inicializando...";
    scrollPadding[] = "                ";
    lcdPosition(lcd, 0, 0);
    lcdClear(lcd);
    scrollTextLeftToRight(0, 0);
    lcdClear(lcd);
}

void menu_1(int menuPosition)
{   
    /*int titleLenth = strlen(title);
    if(titleLenth < strlen(scrollPadding)) {
        int lenthDif = strlen(scrollPadding) - titleLenth;
    }

    char centeredTitle[] = */
    scrollPadding[] = "";
    lcdPosition(lcd, 0, 0); 
    lcdPuts(lcd, "      MENU      ");
    lcdPosition(lcd, 0, 1);
    lcdPutchar(lcd, 10);
    message[] = "   Config   Sele. Sensor   Monitor  ";
    lcdPosition(lcd, 1, 1);
    switch (menuPosition) {
    case 0:
        lcdPuts(lcd, "   Config   ");
        break;
    case 1:
        lcdPuts(lcd, "Sele. Sensor");
        break;
    case 2:
        lcdPuts(lcd, "   Monitor  ");
        break;

    default:
        lcdPuts(lcd, "   Config   ");
        break;
}

    lcdPosition(lcd, 15, 1);
    lcdPutchar(lcd, 11);

}

int main (void)
{
    //WiringOp library setup
    wiringPiSetup();
    //Setting buttons to input mode
    pinMode(BUTTON_NEXT, INPUT);
    pinMode(BUTTON_PREVIOUS, INPUT);
    pinMode(BUTTON_ENTER, INPUT);

    
    int buttonNextState;
    int buttonPreviousState;
    int buttonEnterState;


    

    //Display Initialization
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
    initialization();
    lcdCharDef(lcd, 10, arrowLeftSmall);
    lcdCharDef(lcd, 11, arrowRightSmall); 
    lcdCharDef(lcd, 12, arrowLeftBig);
    lcdCharDef(lcd, 13, arrowRightBig); 
    // UART setup
    /*
    if ((fd = serialOpen ("/dev/ttyS3", 115200)) < 0){
        printf ("Erro de configuracao UART") ;
        return 1 ;
    }*/
    delay(100);
    menu_1(0);

    while(1){
        // Listening to buttons
        buttonNextState = digitalRead(BUTTON_NEXT);
        buttonPreviousState = digitalRead(BUTTON_PREVIOUS);
        buttonEnterState = digitalRead(BUTTON_ENTER);
        
        delay(100);
        message[] = "   Config   Sele. Sensor   Monitor  ";
        lcdPosition(lcd, 1, 1);
        if (!buttonNextState) {
            // O botão foi pressionado
            menuPos ++;
            lcdPosition(lcd, 0, 1);
            lcdPutchar(lcd, 12);
            usleep(100000);
            scrollTextRightToLeft(12, menuPos+11);
        }
        if (!buttonPreviousState) {
            // O botão foi pressionado
            menuPos --;
            lcdPosition(lcd, 15, 1);
            lcdPutchar(lcd, 13);
            usleep(100000);
            scrollTextLeftToRight(12, menuPos-11);
        }


        }
    return 0;
}
