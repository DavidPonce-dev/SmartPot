#include <ArduinoJson.h>

#include "Fetch.cpp"
#include "Model/Pot.cpp"

class PotApi{
    public:
    void begin(String dominio){
		chipID = "{\"chipId:\"";
		chipID+= ESP.getChipId();
		chipID+= "\"}";

		this->dominio = dominio;
		signIn();
	}

	void loop(){
		if(millis() > uploadDelay){
			
			uploadPotData();

			uploadDelay = millis() + 1000;
		}
	}
    
    private:
	Pot pot;
	Fetch fetch;
    String chipID = "";
	String dominio = "";
	String uri = "";
	String data = "";
	unsigned long uploadDelay;

	void signIn(){
		uri = dominio + "/api/signin";
		
		data = fetch.POST(uri, chipID, [](int httpCode, String payload)  -> String {
			if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
				return payload;
			}
			return "";
		});

		Serial.println(this->data);
	}

	void uploadPotData(){
		uri = dominio + "/api/getdata";

		serializeJson(pot.toJsonDocument(), data);
		
		fetch.POST(uri, data, [](int httpCode, String payload) -> String {
			if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
				return payload;
			}
			return "";
		});

	}
};