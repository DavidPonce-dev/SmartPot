#include "Fetch.cpp"

class Pot{
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
    
    private:
    String chipID = "";
    String apiKey = "";
	String dominio = "";
	String uri = "";
	String data = "";
	Fetch fetch;

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