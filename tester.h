#include <iostream>
#include <string>


class Tester : public Angajat {
private:
    bool automatizare;
public:
    Tester(std::string nume, int vechime, bool automatizare)
            : Angajat(id ,nume, vechime), automatizare(automatizare) {}
    ~Tester(){}
    double calculeazaSalariu() const override {
        return 5000 + (automatizare ? 1000 : 0) + 250 * vechimeAni;
    }

    void afiseazaDetalii() const override {
        std::cout << "Tester: " << nume << ", Vechime: " << vechimeAni
                  << " ani, Automatizare: " << (automatizare ? "Da" : "Nu") << std::endl;
    }

    void promoveaza() override {
        std::cout << nume << " a devenit Lead Tester!" << std::endl;
    }

    void genereazaRaportActivitate() const override {
        std::cout << "Raport Tester: " << nume << " efectueaza "
                  << (automatizare ? "testare automata" : "testare manuala") << "." << std::endl;
    }
};