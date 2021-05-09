#include <WiFiManager.h>

void wifiManager() {
    WiFiManager wm;
    WiFiManagerParameter js("<script>var h1 = document.createElement(\"h1\"); h1.innerHTML = \"Configuracion wifi\"; document.querySelector(\"body\").prepend(h1);</script>");
    wm.setCustomHeadElement("<script>if (window.location.href.indexOf(\"/wifi\")<0) {window.location=\"/wifi\"};</script>");
    wm.addParameter(&js);
    wm.setClass("invert");
    wm.setConnectTimeout(20);
    if ( !wm.autoConnect("SmartPot-setup" ) ) {
        Serial.println("Error al conectar");
    }
    else {
        Serial.println("Conectado!!");
    }
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    delay(2000);
    wifiManager();
}

void loop(){
}