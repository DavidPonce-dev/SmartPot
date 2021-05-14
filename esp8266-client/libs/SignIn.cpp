#include "Fetch.cpp"

class SignIn
{
public:
	SignIn(String dominio){
		this->dominio = dominio;
	}

	void begin(){
		if (!login())
			registro();
	}

private:
	String jsonID = (String)"{\"chipId:\":\"" + ESP.getChipId() + "\"}";
	String dominio = "";
	String uri = "";
	String data = "";
	Fetch fetch;

	boolean login(){
		String uri = dominio + "/api/login";
		return false;
	}

	void registro(){
		uri = dominio + "/api/register";
		
		data = fetch.POST(uri, jsonID, [](int httpCode, String payload) {
			Serial.print("http code: ");
			Serial.println(httpCode);
			if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
				return payload;
			}
		});

		Serial.println(this->data);
	}
};