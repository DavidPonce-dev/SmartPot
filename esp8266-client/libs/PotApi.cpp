#include "Fetch.cpp"

class PotApi{
    public:
    void begin(String dominio){
		chipID = "{\"chipId:\"";
		chipID+= ESP.getChipId();
		chipID+= "\"}";

		this->dominio = dominio;
		if (!login()){
			registro();
        }
	}

	void loop(){}
    
    private:
	Fetch fetch;
    String chipID = "";
	String dominio = "";
	String uri = "";
	String data = "";

    boolean login(){
		uri = dominio + "/api/login";
		return false;
	}

	void registro(){
		uri = dominio + "/api/register";
		
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