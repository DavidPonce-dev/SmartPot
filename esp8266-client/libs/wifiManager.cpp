#include <WiFiManager.h>

void wifiManager() {
    WiFi.mode(WIFI_STA);
    WiFiManager wm;
    WiFiManagerParameter js("<script>var h1 = document.createElement(\"h1\"); h1.innerHTML = \"Configuracion wifi\"; document.querySelector(\"body\").prepend(h1);</script>");
    wm.setCustomHeadElement("<script>if (window.location.href.indexOf(\"/wifi\")<0) {window.location=\"/wifi\"};</script>");
    wm.addParameter(&js);
    wm.setClass("invert");
    wm.setConnectTimeout(10);

    while( !wm.autoConnect("SmartPot-setup" ) );
    Serial.println("Conectado");
}