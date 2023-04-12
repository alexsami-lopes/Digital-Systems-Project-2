#include <stdio.h>
#include <wiringPi.h>

#define NUM 22

int main (void)
{
    wiringPiSetup();
    pinMode(NUM, OUTPUT);
    for(;;){
        digitalWrite(NUM, HIGH);    //On
        delay(1000);
        digitalWrite(NUM, LOW);
        delay(1000);
    }
    return 0;
}
