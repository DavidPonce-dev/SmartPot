#include <ESP8266HTTPClient.h>

class Fetch{
    public:
    String GET(String url, String (*callback)(int, String)){
        http.begin(url.c_str());
        httpResponseCode = http.GET();
        payload = http.getString();
        http.end();
        return callback(httpResponseCode, payload);
    }
    String POST(String url, String data, String (*callback)(int, String)){ //(httpCode, response)
        http.begin(url.c_str());
        http.addHeader("Content-Type", "application/json");
        httpResponseCode = http.POST(data);
        payload = http.getString();
        http.end();
        return callback(httpResponseCode, payload);
    }

    private:
    HTTPClient http;
    int httpResponseCode = 0;
    String payload = "";
};