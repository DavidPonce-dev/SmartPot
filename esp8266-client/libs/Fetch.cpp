#include <ESP8266HTTPClient.h>

class Fetch{
    public:
    static void GET(String url, void (*callback)(int, String)){
        http.begin(url.c_str());
        httpResponseCode = http.GET();
        payload = http.getString();
        http.end();
        callback(httpResponseCode, payload);
    }
    static void POST(String url, String data, void (*callback)(int, String)){ //(httpCode, response)
        http.begin(url.c_str());
        http.addHeader("Content-Type", "application/json");
        httpResponseCode = http.POST(data);
        payload = http.getString();
        http.end();
        callback(httpResponseCode, payload);
    }

    private:
    HTTPClient http;
    int httpResponseCode = 0;
    String payload = "";
};