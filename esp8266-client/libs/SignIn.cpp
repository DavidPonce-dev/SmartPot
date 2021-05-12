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

	String getApikey(){
		return apiKey;
	}
	void setApikey(String nApiKey){
		this->apiKey = nApiKey;
	}

private:
	String apiKey = "";
	String dominio = "";
	Fetch fetch;

	boolean login(){
		String uri = dominio + "/api/login";
		return false;
	}

	void registro(){
		String uri = dominio + "/api/register";
		fetch.POST(uri, (String) "{\"id:\":\"" + ESP.getChipId() + "\"}", [](int httpCode, String payload) {
			if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
				Serial.println(payload);
			}
		});
	}
};