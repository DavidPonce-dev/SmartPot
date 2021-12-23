#include <ArduinoJson.h>

#include "Fetch.cpp"

class Pot
{
public:
	void begin(String dominio)
	{
		chipID = "{\"chipId:\"";
		chipID += ESP.getChipId();
		chipID += "\"}";
		uri = dominio + "/api/signin";

		fetch.POST(uri, chipID, [](int httpCode, String payload) -> String
		{
			if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
				return "SUCCESS";
			}
			return "FALIED"; 
		});
	}

	void loop()
	{
		if (millis() > uploadDelay)
		{
			uri = dominio + "/api/pushdata";
			data = "";
			fetch.POST(uri, data, [](int httpCode, String payload) -> String
			{
				if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
					return payload;
				}
				Serial.println(httpCode);
				return ""; 
			});

			uploadDelay = millis() + 1000;
		}
	}

private:
	Fetch fetch;
	String chipID = "";
	String dominio = "";
	String uri = "";
	String data = "";
	unsigned long uploadDelay;
};