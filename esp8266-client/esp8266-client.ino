#include "libs/wifiManager.cpp"
#include "libs/SignIn.cpp"

SignIn signIn("http://192.168.43.236:3000");

void setup() {
    Serial.begin(115200);
    wifiManager();
    signIn.begin();
}

void loop(){
}