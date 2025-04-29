#include <exception>
#include <iostream>
#include <string>
#include <vector>

class Meniu {
private:
    std::vector<Angajat*> angajati;
public:
    void afiseazaMeniu() {
        int n;
        do {
            std::cout << "1. Adauga angajat" << std::endl
                      << "2. Afiseaza detalii angajat" << std::endl
                      << "3. Promoveaza angajat" << std::endl
                      << "4. Calculeaza salariu angajat" << std::endl
                      << "5. Genereaza raport activitate" << std::endl
                      << "0. Iesire" << std::endl;
            std::cin>>n;
            switch(n) {
                case 1: {
                    int m;
                    std::cout << "Functie angajat?" << std::endl
                              << "1. Manager" << std::endl
                              << "2. Programator" << std::endl
                              << "3. Tester" << std::endl;
                    std::cin >> m;
                    if (m < 1 || m > 3)
                        throw FunctieNecunoscutaException();

                    std::string nume;
                    int vechime;
                    std::cout << "Introdu numele: ";
                    std::cin.ignore();
                    getline(std::cin, nume);
                    if (nume.empty())
                        throw DateIncompleteException();

                    std::cout << "Introdu vechimea in ani: ";
                    std::cin >> vechime;
                    if (vechime < 0)
                        throw DateIncompleteException();

                    Angajat* a = nullptr;
                    if (m == 1) {
                        int nrEchipe;
                        std::cout << "Numar echipe conduse: ";
                        std::cin >> nrEchipe;
                        a = new Manager(nume, vechime, nrEchipe);
                    } else if (m == 2) {
                        std::string limbaj;
                        std::cout << "Limbaj principal: ";
                        std::cin >> limbaj;
                        a = new Programator(nume, vechime, limbaj);
                    } else if (m == 3) {
                        bool automatizare;
                        std::cout << "Face testare automata? (1.Da / 0.Nu): ";
                        std::cin >> automatizare;
                        if(automatizare!=1 && automatizare!=0)
                            throw ExceptieAngajat();
                        a = new Tester(nume, vechime, automatizare);
                    }

                    if (a != nullptr) {
                        angajati.push_back(a);
                        std::cout << "Angajat adaugat cu ID-ul " << a->getId() << std::endl;
                    }
                    break;
                }
                case 2: {
                    int id_cautat;
                    std::cout << "Introdu ID angajat pentru afisare detalii: ";
                    std::cin >> id_cautat;
                    bool gasit = false;
                    for (auto ang : angajati) {
                        if (ang->getId() == id_cautat) {
                            ang->afiseazaDetalii();
                            gasit = true;
                        }
                    }
                    if (!gasit) std::cout << "Angajatul nu a fost gasit!" << std::endl;
                    break;
                }
                case 3: {
                    int id_cautat;
                    std::cout << "Introdu ID angajat pentru promovare: ";
                    std::cin >> id_cautat;
                    bool gasit = false;
                    for (auto ang : angajati) {
                        if (ang->getId() == id_cautat) {
                            ang->promoveaza();
                            gasit = true;
                        }
                    }
                    if (!gasit) std::cout << "Angajatul nu a fost gasit!" << std::endl;
                    break;
                }
                case 4: {
                    int id_cautat;
                    std::cout << "Introdu ID angajat pentru calcul salariu: ";
                    std::cin >> id_cautat;
                    bool gasit = false;
                    for (auto ang : angajati) {
                        if (ang->getId() == id_cautat) {
                            std::cout << "Salariul este: " << ang->calculeazaSalariu() << " RON" << std::endl;
                            gasit = true;
                        }
                    }
                    if (!gasit) std::cout << "Angajatul nu a fost gasit!" << std::endl;
                    break;
                }
                case 5: {
                    if (angajati.empty())
                        throw DateIncompleteException();

                    int id_cautat;
                    std::cout << "Introdu ID-ul angajatului: ";
                    std::cin >> id_cautat;
                    bool gasit = false;
                    for (auto ang : angajati) {
                        if (ang->getId() == id_cautat) {
                            gasit = true;
                            if (n == 2)
                                ang->afiseazaDetalii();
                            else if (n == 3)
                                ang->promoveaza();
                            else if (n == 4)
                                std::cout << "Salariu: " << ang->calculeazaSalariu() << " RON" << std::endl;
                            else if (n == 5)
                                ang->genereazaRaportActivitate();
                            break;
                        }
                    }
                    if (!gasit)
                        throw IdInvalidException();
                    break;
                }
                case 0:
                    std::cout << "Iesire din program." << std::endl;
                    break;
                default:
                    std::cout << "Optiune invalida!" << std::endl;
            }
        } while (n != 0);
    }
};