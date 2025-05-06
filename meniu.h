#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Meniu {
private:
    std::vector<Angajat*> angajati;
public:

    void salveazaInFisier() {
        std::ofstream fout("angajati.txt");
        for (auto ang : angajati) {
            if (auto m = dynamic_cast<Manager*>(ang)) {
                fout << "1 " << m->getId() << " " << m->getNume() << " " << m->getPrenume() << " "
                     << m->getVechimeAnt() << " " << m->getDataAngajareString() << " "
                     << m->getDataNastereString() << " " << m->getStudii() << " "<< m->getPromovat() <<" "<<
                     m->getNrEchipe() << "\n";
            } else if (auto p = dynamic_cast<Programator*>(ang)) {
                fout << "2 " << p->getId() << " " << p->getNume() << " " << p->getPrenume() << " "
                     << p->getVechimeAnt() << " " << p->getDataAngajareString() << " "
                     << p->getDataNastereString() << " " << p->getStudii() << " "<< p->getPromovat()<<" "
                     << p->getLimbaj() << "\n";
            } else if (auto t = dynamic_cast<Tester*>(ang)) {
                fout << "3 " << t->getId() << " " << t->getNume() << " " << t->getPrenume() << " "
                     << t->getVechimeAnt() << " " << t->getDataAngajareString() << " "
                     << t->getDataNastereString() << " " << t->getStudii() << " "<< t->getPromovat()
                     <<" "<< t->getAutomatizare() << "\n";
            }
        }
        fout.close();
        std::cout << "Datele au fost salvate cu succes.\n";
    }
    void incarcaDinFisier() {
        std::ifstream fin("angajati.txt");
        if (!fin) {
            std::cout<<"Nu exista fisier.\n";
            return;
        }
        int tip;
        while (fin >> tip) {
            bool promovat;
            int id, vechime, ziA, lunaA, anA, ziN, lunaN, anN;
            std::string nume, prenume, studii;
            fin >> id >> nume >> prenume >> vechime >> ziA >> lunaA >> anA >> ziN >> lunaN >> anN >> studii >> promovat;

            std::tm dataAng = {};
            dataAng.tm_mday = ziA;
            dataAng.tm_mon = lunaA - 1;
            dataAng.tm_year = anA - 1900;

            std::tm dataNast = {};
            dataNast.tm_mday = ziN;
            dataNast.tm_mon = lunaN - 1;
            dataNast.tm_year = anN;

            Angajat* a = nullptr;
            if (tip == 1) {
                int echipe;
                fin >> echipe;
                a = new Manager(nume, prenume, vechime, dataAng, dataNast, studii, promovat,echipe);
            } else if (tip == 2) {
                std::string limbaj;
                fin >> limbaj;
                a = new Programator(nume, prenume, vechime, dataAng, dataNast, studii, promovat, limbaj);
            } else if (tip == 3) {
                bool autoTest;
                fin >> autoTest;
                a = new Tester(nume, prenume, vechime, dataAng, dataNast, studii, promovat, autoTest);
            }

            if (a != nullptr)
                angajati.push_back(a);
        }

        fin.close();
        std::cout << "Datele au fost incarcate din fisier.\n";
    }

    void afiseazaMeniu() {
        int n;
        std::cout << "Doriti sa recuperati datele din fisier?\n 1. Da \n 2. Nu\n";
        std::cin>> n;
        if(n==1)
            incarcaDinFisier();
        do {
            std::cout << "1. Adauga angajat" << std::endl
                      << "2. Afiseaza detalii angajat" << std::endl
                      << "3. Promoveaza angajat" << std::endl
                      << "4. Genereaza raport activitate" << std::endl
                      << "5. Afiseaza detaliile tuturor angajatilor"<< std::endl
                      << "6. Salveaza datele curente"<< std::endl
                      << "7. Sterge un angajat"<< std::endl
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
                    std::cout << "Introdu nume: ";
                    std::cin.ignore();
                    getline(std::cin, nume);
                    if (nume.empty())
                        throw DateIncompleteException();

                    std::string prenume;
                    std::cout << "Introdu prenume: ";
                    getline(std::cin, prenume);
                    if (prenume.empty())
                        throw DateIncompleteException();
                    int anNastere, lunaNastere, ziNastere;
                    std::cout << "Introdu data de nastere (zi, luna, an): ";
                    std::cin >> ziNastere >> lunaNastere >> anNastere;
                    if (anNastere < 1900 || lunaNastere < 1 || lunaNastere > 12 || ziNastere < 1 || ziNastere > 31)
                        throw DateIncompleteException();

                    std::string studii;
                    std::cout<< "Introdu studii (Liceu, Licenta, Master, Docorat): ";
                    std::cin.ignore();
                    getline( std::cin, studii);
                    if(studii != "Liceu" && studii != "Licenta" && studii != "Master" && studii != "Doctorat")
                        throw DateIncompleteException();

                    std::tm dataNastere = {};
                    dataNastere.tm_mday = ziNastere;
                    dataNastere.tm_mon = lunaNastere - 1;
                    dataNastere.tm_year = anNastere;

                    std::cout << "Introdu vechimea in ani: ";
                    std::cin >> vechime;
                    if (vechime < 0)
                        throw DateIncompleteException();

                    int an, luna, zi;
                    std::cout << "Introdu data angajarii (zi, luna, an): ";
                    std::cin >> zi >> luna >> an;
                    if (an < 1900 || luna < 1 || luna > 12 || zi < 1 || zi > 31)
                        throw DateIncompleteException();

                    std::tm dataAngajare = {};
                    dataAngajare.tm_mday = zi;
                    dataAngajare.tm_mon = luna - 1;
                    dataAngajare.tm_year = an - 1900;

                    Angajat* a = nullptr;
                    if (m == 1) {
                        int nrEchipe;
                        std::cout << "Numar echipe conduse: ";
                        std::cin >> nrEchipe;
                        a = new Manager(nume, prenume, vechime, dataAngajare, dataNastere, studii, false, nrEchipe);
                    } else if (m == 2) {
                        std::string limbaj;
                        std::cout << "Limbaj principal: ";
                        std::cin >> limbaj;
                        a = new Programator(nume, prenume, vechime, dataAngajare, dataNastere, studii, false, limbaj);
                    } else if (m == 3) {
                        bool automatizare;
                        std::cout << "Face testare automata? (1.Da / 0.Nu): ";
                        std::cin >> automatizare;
                        if(automatizare!=1 && automatizare!=0)
                            throw ExceptieAngajat();
                        a = new Tester(nume, prenume, vechime, dataAngajare, dataNastere, studii, false, automatizare);
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

                    int counterTot=0, counterMan = 0, counterTester = 0, counterProg = 0, salariuMediu=0;
                    if(angajati.empty()) {
                        std::cout << "Nu exista angajati!";
                        break;
                    }
                    for (const auto &ang: angajati) {
                        if (auto m = dynamic_cast<Manager *>(ang)) {
                            counterMan++;
                            counterTot++;
                            salariuMediu = (salariuMediu + m->getSalariu())/counterTot;
                        }
                        else if (auto p = dynamic_cast<Programator *>(ang)) {
                            counterProg++;
                            counterTot++;
                            salariuMediu = (salariuMediu + p->getSalariu()) / counterTot;
                        }
                        else if (auto t = dynamic_cast<Tester *>(ang)) {
                            counterTester++;
                            counterTot++;
                            salariuMediu = (salariuMediu + t->getSalariu()) / counterTot;
                        }
                    }
                    std::cout << "Nr total angajati: " <<counterTot;
                    std::cout << "\nNr angajati manageri: "<<counterMan;
                    std::cout << "\nNr angajati programatori: "<<counterProg;
                    std::cout << "\nNr angajati testeri: "<<counterTester;
                    std::cout << "\nSalariu mediu: "<<salariuMediu << std::endl;
                }
                    break;
                case 5:
                    std::cout << "Detalii angajati\n";
                    for(const auto &angajat : angajati)
                        angajat->afiseazaDetalii();
                    break;
                case 6:
                    salveazaInFisier();
                    break;
                case 7: {
                    int id_de_sters;
                    std::cout << "Introdu ID angajat pentru stergere: ";
                    std::cin >> id_de_sters;
                    bool sters = false;
                    for (auto it = angajati.begin(); it != angajati.end(); ++it) {
                        if ((*it)->getId() == id_de_sters) {
                            delete *it; // șterge obiectul din memorie
                            angajati.erase(it); // șterge pointerul din vector
                            std::cout << "Angajatul cu ID-ul " << id_de_sters << " a fost sters.\n";
                            sters = true;
                            break;
                        }
                    }
                    if (!sters)
                        std::cout << "Angajatul cu ID-ul " << id_de_sters << " nu a fost gasit.\n";
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