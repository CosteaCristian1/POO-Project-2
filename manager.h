#include <iostream>
#include <string>


class Manager : public Angajat {
private:
    int nrEchipeConduse;
public:
    Manager(std::string nume, std::string prenume, int vechime, std::tm dataAngajare,std::tm dataNasterii, std::string studii,bool promovat,
            int nrEchipe)
            : Angajat(id, nume, prenume, vechime, dataAngajare, dataNasterii, studii, promovat), nrEchipeConduse(nrEchipe) {
        this->salariu= calculeazaSalariu();
    }
    ~Manager(){}
    double calculeazaSalariu() const override {
        return 8000 + 500 * nrEchipeConduse + 200 * vechimeTotala + 300 * promovat;
    }

    void afiseazaDetalii() const override {
        std::cout << "Manager: " << nume << " "<< prenume << "\n Data nasterii:" << dataNasterii.tm_mday
                  << "." << dataNasterii.tm_mon << "." << dataNasterii.tm_year << "\n Vechime: " << vechimeTotala
                  << " ani\n Echipe: " << nrEchipeConduse << "\n Data angajare: " << dataAngajare.tm_mday  << "."
                  << dataAngajare.tm_mon+1 << "." << dataAngajare.tm_year+1900 << "\n Salariu:" << salariu << "\n Studii:"
                  << studii << std::endl;
    }

    void promoveaza() override {
        if(promovat==false) {
            nrEchipeConduse++;
            promovat = true;
        }
        else {
            std::cout << "Angajatul a fost deja promovat!";
            return;
        }
        this->salariu=calculeazaSalariu();
        std::cout << nume << " a fost promovat ca Manager Senior! Echipe conduse: "
                  << nrEchipeConduse << std::endl;
    }

    void genereazaRaportActivitate() const override {
        std::cout << "Raport Manager: " << nume << " conduce "
                  << nrEchipeConduse << " echipe." << std::endl;
    }
    const int getNrEchipe(){
        return nrEchipeConduse;
    }
};
