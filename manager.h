#include <iostream>
#include <string>


class Manager : public Angajat {
private:
    int nrEchipeConduse;
public:
    Manager(std::string nume, int vechime, int nrEchipe)
            : Angajat(id, nume, vechime), nrEchipeConduse(nrEchipe) {}
    ~Manager(){}
    double calculeazaSalariu() const override {
        return 8000 + 500 * nrEchipeConduse + 200 * vechimeAni;
    }

    void afiseazaDetalii() const override {
        std::cout << "Manager: " << nume << ", Vechime: " << vechimeAni
                  << " ani, Echipe: " << nrEchipeConduse << std::endl;
    }

    void promoveaza() override {
        nrEchipeConduse++;
        std::cout << nume << " a fost promovat ca Manager Senior! Echipe conduse: "
                  << nrEchipeConduse << std::endl;
    }

    void genereazaRaportActivitate() const override {
        std::cout << "Raport Manager: " << nume << " conduce "
                  << nrEchipeConduse << " echipe." << std::endl;
    }
};
