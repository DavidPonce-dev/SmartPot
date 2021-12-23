#include <WiFiManager.h>
#include "libs/PotApi.cpp"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);
PotApi pot;

void lcdInit() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hola! SmartPot");
  lcd.setCursor(0, 1);
  lcd.print("V0.0.1");
  delay(2000);
}

void lcdConfig(WiFiManager *myWiFiManager)
{
  lcd.setCursor(0, 0);
  lcd.println("Wifi config mode");
  lcd.setCursor(0, 1);
  lcd.println(myWiFiManager->getConfigPortalSSID());
}

void lcdConnected(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Conectado!!");
  lcd.setCursor(0,1);
  lcd.print(" a la red");
  delay(2000);
}

void wmSetup()
{
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  WiFiManagerParameter js("<script>var h1 = document.createElement(\"h1\"); h1.innerHTML = \"Configuracion wifi\"; document.querySelector(\"body\").prepend(h1);</script>");
  wm.setCustomHeadElement("<script>if (window.location.href.indexOf(\"/wifi\")<0) {window.location=\"/wifi\"};</script>");
  wm.addParameter(&js);
  wm.setClass("invert");
  wm.setConnectTimeout(10);
  wm.setAPCallback(lcdConfig);

  if (!wm.autoConnect("SmartPot-setup"))
    ESP.restart();
}

void setup()
{
  Serial.begin(115200);
  lcdInit();
  wmSetup();
  lcdConnected();
  pot.begin("http://192.168.43.236:3000");
}

void loop()
{
  pot.loop();
}