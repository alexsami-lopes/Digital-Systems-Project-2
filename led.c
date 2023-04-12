#include <lcd.h>
#include <wiringPi.h>

// Led Pin number
#define LED 22

int main() {
    short lcd;
    wiringPiSetup();
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
    return 0;
}
