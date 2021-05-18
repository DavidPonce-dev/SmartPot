#include <WiFiManager.h>
#include "libs/PotApi.cpp"

PotApi pot;

const char* apSSID = "SmartPot-setup";

void wifiManagerConfig() {
    WiFi.mode(WIFI_STA);
    WiFiManager wm;
    WiFiManagerParameter js("<script>var h1 = document.createElement(\"h1\"); h1.innerHTML = \"Configuracion wifi\"; document.querySelector(\"body\").prepend(h1);</script>");
    wm.setCustomHeadElement("<script>if (window.location.href.indexOf(\"/wifi\")<0) {window.location=\"/wifi\"};</script>");
    wm.addParameter(&js);
    wm.setClass("invert");
    wm.setConnectTimeout(10);

    if( !wm.autoConnect( apSSID ) ) ESP.restart();
}

void setup() {
    Serial.begin(115200);
    wifiManagerConfig();
    pot.begin("http://192.168.43.236:3000");
}

void loop(){
}