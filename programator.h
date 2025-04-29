#include <iostream>
#include <string>


class Programator : public Angajat {
private:
    std::string limbajPrincipal;
public:
    Programator(std::string nume, int vechime, std::string limbaj)
            : Angajat(id ,nume, vechime), limbajPrincipal(limbaj) {}
    ~Programator(){}
    double calculeazaSalariu() const override {
        return 6000 + 300 * vechimeAni;
    }

    void afiseazaDetalii() const override {
        std::cout << "Programator: " << nume << ", Vechime: " << vechimeAni
                  << " ani, Limbaj: " << limbajPrincipal << std::endl;
    }

    void promoveaza() override {
        std::cout << nume << " a fost promovat la Programator Senior in " << limbajPrincipal << "!" << std::endl;
    }

    void genereazaRaportActivitate() const override{
        std::cout << "Raport Programator: " << nume << " scrie cod in "
                  << limbajPrincipal << "." << std::endl;
    }
};
