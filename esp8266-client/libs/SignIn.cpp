#include "Fetch.cpp"

class SignIn{
    public:

    void begin(String loginURI, String registerURI) {
        if ( !login(loginURI) ) registro(registerURI);
    }

    private:

    Fetch fetch;

    boolean login(String uri) {
        return false;
    }

    void registro(String uri) {
        String response = "";
        fetch.GET( uri, [&response] (int httpCode, String payload){
            if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
                response = payload;
            }
        } );
        Serial.println(response);
    }
};