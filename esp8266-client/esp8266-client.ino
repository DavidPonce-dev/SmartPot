#include "libs/wifiManager.cpp"
#include "libs/SignIn.cpp"

String dominio = "http://192.168.43.236:3000";
SignIn signIn;

void setup() {
    Serial.begin(115200);
    wifiManager();
    signIn.begin(dominio + "/api/login", dominio + "/api/register");
}

void loop(){
}