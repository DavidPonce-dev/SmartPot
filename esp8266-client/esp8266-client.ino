#include <WiFiManager.h>
#include "libs/PotApi.cpp"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

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
    
  lcd.init();            // our display has 16 cols, 2 rows
  lcd.backlight();      // Turn on the backlight
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("Ywrobot Arduino!");

    Serial.begin(115200);
    wifiManagerConfig();
    pot.begin("http://192.168.43.236:3000");
}

void loop(){
}