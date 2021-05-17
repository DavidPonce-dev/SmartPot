class Pot{
    public:

    Pot();

    Pot(String apikey, int waterLvl, int ppm, int ph){
        this->waterLevel = waterLvl;
        this->density = ppm;
        this->waterPh = ph;
    }

    private:
    String apikey;
    int waterLevel=0;
    int density=0;
    int waterPh=0;
};