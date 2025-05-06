#include <iostream>
#include <string>


class Tester : public Angajat {
private:
    bool automatizare;
public:
    Tester(std::string nume, std::string prenume, int vechime, std::tm dataAngajare, std::tm dataNasterii, std::string studii, bool promovat,
           bool automatizare)
            : Angajat(id ,nume, prenume, vechime, dataAngajare, dataNasterii, studii, promovat), automatizare(automatizare) {
        this->salariu= calculeazaSalariu();
    }
    ~Tester(){}
    double calculeazaSalariu() const override {
        return 5000 + (automatizare ? 1000 : 0) + 250 * vechimeTotala + 300 * promovat;
    }

    void afiseazaDetalii() const override {
        std::cout << "Tester: " << nume << " " << prenume << "\n Data nasterii:" << dataNasterii.tm_mday
                  << "." << dataNasterii.tm_mon << "." << dataNasterii.tm_year <<  ",\n Vechime: " << vechimeTotala
                  << " ani,\n Automatizare: " << (automatizare ? "Da" : "Nu") << "\n Data angajare: " << dataAngajare.tm_mday  << "."
                  << dataAngajare.tm_mon+1 << "." << dataAngajare.tm_year+1900 << "\n Salariu:" << salariu << "\n Studii:"
                  << studii << std::endl;
    }

    void promoveaza() override {
        promovat=true;
        this->salariu=calculeazaSalariu();
        std::cout << nume << " a devenit Lead Tester!" << std::endl;
    }

    void genereazaRaportActivitate() const override {
        std::cout << "Raport Tester: " << nume << " efectueaza "
                  << (automatizare ? "testare automata" : "testare manuala") << "." << std::endl;
    }
    const bool getAutomatizare(){return automatizare;}
};