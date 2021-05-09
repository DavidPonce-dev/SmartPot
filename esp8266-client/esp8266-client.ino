#include <WiFiManager.h>

void setup() {
    Serial.begin(115200);
    WiFiManager wm;
    if ( !wm.autoConnect("SmartPot-setup" ) ) {
        Serial.println("Error al conectar");
    }
    else {
        Serial.println("Conectado!!");
    }
}

void loop(){
}