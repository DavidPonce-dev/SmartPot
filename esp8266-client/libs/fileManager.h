#include <ESP8266WiFi.h>
#include <LittleFS.h>

const char* fsName = "LittleFS";
FS* fileSystem = &LittleFS;
LittleFSConfig fileSystemConfig = LittleFSConfig();

File archivo;
String res;

boolean fsBegin(){
  fileSystemConfig.setAutoFormat(false);
  fileSystem->setConfig(fileSystemConfig);
  return fileSystem->begin();
}

String loadFile(String pathFile){
  archivo = fileSystem->open(pathFile, "r");
  res = "";
  if (archivo) {
    while (archivo.available()) {
      res += archivo.read();
    }
  }
  archivo.close();
  return res;
}

boolean saveFile(String pathFile, String payload){
  archivo = fileSystem->open(pathFile, "w");
  if (archivo) {
    archivo.print(payload);
    archivo.close();
    return true;
  }
  archivo.close();
  return false;
}