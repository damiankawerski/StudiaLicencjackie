#include <iostream>
#include <memory>
#include <string>

class Samochod {
public:
    std::string silnik;
    std::string nadwozie;
    std::string kola;

    void show() {
        std::cout << "Samochód z silnikiem: " << silnik 
                  << ", nadwoziem: " << nadwozie 
                  << ", kołami: " << kola << std::endl;
    }
};


class SamochodBuilder {
public:
    virtual void zbudujSilnik() = 0;
    virtual void zbudujNadwozie() = 0;
    virtual void zbudujKola() = 0;
    virtual std::shared_ptr<Samochod> getSamochod() = 0;
    virtual ~SamochodBuilder() {}
};



class SportowyBuilder : public SamochodBuilder {
private:
    std::shared_ptr<Samochod> samochod;

public:
    SportowyBuilder() {
        samochod = std::make_shared<Samochod>();
    }

    void zbudujSilnik() override {
        samochod->silnik = "V8";
    }

    void zbudujNadwozie() override {
        samochod->nadwozie = "Coupe";
    }

    void zbudujKola() override {
        samochod->kola = "19 cali sportowe";
    }

    std::shared_ptr<Samochod> getSamochod() override {
        return samochod;
    }

};

int main() {
    SportowyBuilder builder;

    builder.zbudujKola();
    builder.zbudujNadwozie();
    builder.zbudujSilnik();
    std::shared_ptr<Samochod> sportowy = builder.getSamochod();
    sportowy->show();


    return 0;
}