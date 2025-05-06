#include <iostream>
#include <string>
#include <ctime>

class Angajat {
protected:
    int id;
    std::string nume;
    std::string prenume;
    std::tm dataNasterii;
    int vechimeAni;
    std::tm dataAngajare{};
    static int counter;
    int vechimeTotala;
    int salariu;
    std::string studii;
    bool promovat;
public:
    static void counterAdd()
    {
        counter++;
    }
    Angajat(int id, std::string nume, std::string prenume, int vechime, std::tm dataAngajare, std::tm dataNasterii, std::string studii
    , bool promovat) : id(id) ,nume(nume), prenume(prenume), vechimeAni(vechime), dataAngajare(dataAngajare), dataNasterii(dataNasterii), studii(studii), promovat(promovat){
        counterAdd();
        this->id=counter;
        this->vechimeTotala=calculeazaVechimeActuala();
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

    int getId() const { return id; }
    std::string getNume() const { return nume; }
    std::string getPrenume() const { return prenume; }
    std::tm getDataNasterii() const { return dataNasterii; }
    std::tm getDataAngajare() const { return dataAngajare; }

    std::string getDataNastereString() const {
        return std::to_string(dataNasterii.tm_mday) + " " +
               std::to_string(dataNasterii.tm_mon + 1) + " " +
               std::to_string(dataNasterii.tm_year);
    }

    std::string getDataAngajareString() const {
        return std::to_string(dataAngajare.tm_mday) + " " +
               std::to_string(dataAngajare.tm_mon + 1) + " " +
               std::to_string(dataAngajare.tm_year + 1900);
    }

    int getVechimeAnt() const { return vechimeAni; }
    int getVechimeTotala() const { return vechimeTotala; }
    int getSalariu() const { return salariu; }

    int calculeazaVechimeActuala() const {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);

        int ani = now->tm_year - dataAngajare.tm_year;

        if (now->tm_mon < dataAngajare.tm_mon ||
            (now->tm_mon == dataAngajare.tm_mon && now->tm_mday < dataAngajare.tm_mday)) {
            ani--;
        }

        return vechimeAni + ani;
    }
    const int getSalariu(){
        return this->salariu;
    }
    const std::string getStudii(){return this->studii;}
    const bool getPromovat(){
        return this->promovat;
    }

};