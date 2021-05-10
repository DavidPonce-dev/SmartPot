#include "libs/wifiManager.cpp"
#include "libs/SignIn.cpp"

String dominio = "http://192.168.43.168:3000";
SignIn signIn;

void setup() {
    Serial.begin(115200);
    wifiManager();
    signIn.begin(dominio + "/login", dominio + "/register");
}

void loop(){
}