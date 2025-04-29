#include <iostream>
#include <string>

class Angajat {
protected:
    int id;
    std::string nume;
    int vechimeAni;
    static int counter;
public:
    Angajat(int id, std::string nume, int vechime) : id(id) ,nume(nume), vechimeAni(vechime) {
        this->id= ++counter;
    }
    virtual ~Angajat() {}

    virtual double calculeazaSalariu() const = 0;
    virtual void afiseazaDetalii() const = 0;
    virtual void promoveaza() {
        std::cout << nume << " a fost promovat! Crestere de salariu." << std::endl;
    }
    virtual void genereazaRaportActivitate() const {
        std::cout << "Raport generic pentru angajatul " << nume << "." << std::endl;
    }
    const int getId() {
        return this->id;
    }

};