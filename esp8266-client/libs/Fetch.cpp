#include <ESP8266HTTPClient.h>

class Fetch{
    public:
    void GET(String url, (*callback)(int, String) -> void){
        http.begin(url.c_str());
        httpResponseCode = http.GET();
        payload = http.getString();
        http.end();
        callback(httpResponseCode, payload);
    }
    void POST(){}
    void PUT(){}
    void DELETE(){}

    private:
    HTTPClient http;
    int httpResponseCode = 0;
    String payload = "";
};