#include <iostream>
#include <string>


class Programator : public Angajat {
private:
    std::string limbajPrincipal;
public:
    Programator(std::string nume, std::string prenume, int vechime, std::tm dataAngajare, std::tm dataNasterii, std::string studii,
                bool promovat, std::string limbaj)
            : Angajat(id ,nume, prenume, vechime, dataAngajare, dataNasterii, studii, promovat), limbajPrincipal(limbaj) {
        this->salariu= calculeazaSalariu();
    }
    ~Programator(){}
    double calculeazaSalariu() const override {
        if(limbajPrincipal=="Java")
            return 6000 + 300 * vechimeTotala + 300 * promovat;
        if(limbajPrincipal=="Python")
            return 5000 + 300 * vechimeTotala + 300 * promovat;
        if(limbajPrincipal=="PHP")
            return 7000 + 300 * vechimeTotala + 300 * promovat;
    }

    void afiseazaDetalii() const override {
        std::cout << "Programator: " << nume << " "<< prenume << "\n Data nasterii:" << dataNasterii.tm_mday
                  << "." << dataNasterii.tm_mon << "." << dataNasterii.tm_year <<  "\n Vechime: " << vechimeTotala
                  << " ani\n Limbaj: " << limbajPrincipal << "\n Data angajare: " << dataAngajare.tm_mday  << "."
                  << dataAngajare.tm_mon+1 << "." << dataAngajare.tm_year+1900 << "\n Salariu:" << salariu << "\n Studii:"
                  << studii << std::endl;
    }

    void promoveaza() override {
        promovat=true;
        this->salariu=calculeazaSalariu();
        std::cout << nume << " a fost promovat la Programator Senior in " << limbajPrincipal << "!" << std::endl;
    }

    void genereazaRaportActivitate() const override{
        std::cout << "Raport Programator: " << nume << " scrie cod in "
                  << limbajPrincipal << "." << std::endl;
    }
    const std::string getLimbaj(){
        return limbajPrincipal;
    }
};
