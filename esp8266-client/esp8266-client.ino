#include "libs/wifiManager.cpp"
#include "libs/SignIn.cpp"

String dominio = "http://localhost:3000";
SignIn signIn;

void setup() {
    Serial.begin(115200);
    Serial.print("\n");
    Serial.print("\n");
    Serial.print("Iniciando Smartpot...\n");
    delay(2000);
    wifiManager();
    delay(2000);
    signIn.begin(dominio + "/login", dominio + "/register");
}

void loop(){
}