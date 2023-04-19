include <ESP8266WiFi.h>
include <ESP8266mDNS.h>
include <WiFiUdp.h>
include <ArduinoOTA.h>
ifndef STASSID
//nome da rede wifi

define STASSID "INTELBRAS"
//senha da rede

define STAPSK "Pbl-Sistemas-Digitais"
endif
const char ssid = STASSID;
const char password = STAPSK;
//Este valor precisa ser mudado para o ip da placa
const char* host = "ESP-10.0.0.108";

int led_pin = LED_BUILTIN;

define N_DIMMERS 3
int dimmer_pin[] = {14, 5, 15};

void setup() {
//Serial.begin(115200);

/ switch on led /
pinMode(led_pin, OUTPUT);
pinMode(D0, INPUT);
//valor de fronteira serial do ESP8266
Serial.begin(9600);

Serial.println("Booting");
WiFi.mode(WIFI_STA);

WiFi.begin(ssid, password);

while (WiFi.waitForConnectResult() != WL_CONNECTED) {
WiFi.begin(ssid, password);
Serial.println("Retrying connection...");
}
/ switch off led /
digitalWrite(led_pin, HIGH);

/ configure dimmers, and OTA server events /
analogWriteRange(1000);
analogWrite(led_pin, 990);

for (int i = 0; i < N_DIMMERS; i++) {
pinMode(dimmer_pin[i], OUTPUT);
analogWrite(dimmer_pin[i], 50);
}

ArduinoOTA.setHostname(host);
ArduinoOTA.onStart( { // switch off all the PWMs during upgrade
for (int i = 0; i < N_DIMMERS; i++) {
analogWrite(dimmer_pin[i], 0);
}
analogWrite(led_pin, 0);
});

ArduinoOTA.onEnd( { // do a fancy thing with our board led at end
for (int i = 0; i < 30; i++) {
analogWrite(led_pin, (i * 100) % 1001);
delay(50);
}
});

ArduinoOTA.onError([](ota_error_t error) {
(void)error;
ESP.restart();
});

/ setup the OTA server /
ArduinoOTA.begin();
Serial.println("Ready");

}

void loop() {
ArduinoOTA.handle();
//código que coloca o botão D0 para leitura em alto, ou seja, 1
if(digitalRead(D0) == HIGH){
//Se o botão estiver alto led_pin que é o led integrado vai para alto
digitalWrite(led_pin, HIGH);
} else {
// caso contrario o led integrado fica em baixo, ou seja, deligado
digitalWrite(led_pin, LOW);
}

}
