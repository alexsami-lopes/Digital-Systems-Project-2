#include <lcd.h>
#include <wiringPi.h>

// Led Pin number
#define LED 22

int main() {
    
    wiringPiSetup();
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
    return 0;
    
}
