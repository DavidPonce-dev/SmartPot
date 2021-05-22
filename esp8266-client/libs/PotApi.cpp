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

	void loop(){}
    
    private:
	Pot pot();
	Fetch fetch;
    String chipID = "";
	String dominio = "";
	String uri = "";
	String data = "";

	void signIn(){
		uri = dominio + "/api/signin";
		
		data = fetch.POST(uri, chipID, [](int httpCode, String payload) {
			Serial.print("http code: ");
			Serial.println(httpCode);
			if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
				return payload;
			}
		});

		Serial.println(this->data);
	}
};