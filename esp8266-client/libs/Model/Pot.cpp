#include <ArduinoJson.h>

class Pot{
    public:

    Pot(){}

    Pot(String apikey, int waterLvl, int ppm, int ph){
        this->waterLevel = waterLvl;
        this->density = ppm;
        this->waterPh = ph;
        this->apikey = apikey;
    }

    //toJsonDocument

    DynamicJsonDocument toJsonDocument(){
        DynamicJsonDocument doc(1);
        doc["waterLevel"] = this->waterLevel;
        doc["density"] = this->density;
        doc["waterPh"] = this->waterPh;
        doc["apikey"] = this->apikey;
        return doc;
    }

    //getters & setters

    String getApikey(){
        return apikey;
    }

    int getWaterLevel(){
        return waterLevel;
    }

    int getDensity(){
        return density;
    }

    int getWaterPh(){
        return waterPh;
    }

    void setApikey(String apikey){
        this->apikey = apikey;
    }

    void setWaterLevel(int waterLevel){
        this->waterLevel = waterLevel;
    }

    void setDensity(int density){
        this->density = density;
    }

    void setWaterPh(int waterPh){
        this->waterPh = waterPh;
    }

    private:
    String apikey;
    int waterLevel=0;
    int density=0;
    int waterPh=0;
};