#include "libs/wifiManager.cpp"

void setup() {
    Serial.begin(115200);
    Serial.print("\n");
    Serial.print("\n");
    Serial.print("Iniciando Smartpot...\n");
    delay(2000);
    wifiManager();
}

void loop(){
}