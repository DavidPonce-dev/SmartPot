#include "Fetch.cpp"

class SignIn{
    public:

    void begin(String loginURI, String registerURI) {
        Serial.println("Estableciendo conexion");
        if ( !login(loginURI) ) registro(registerURI);
    }

    private:
        boolean login(String uri) {
            return false;
        }

        void registro(String uri) {
            fetch.GET( uri, [] (int httpCode, String payload){
                Serial.print("codigo HTTP: ");
                Serial.println( httpCode );
                if(httpCode > 0) {
                    Serial.println(payload);
                }
            } );
        }
        Fetch fetch;
};