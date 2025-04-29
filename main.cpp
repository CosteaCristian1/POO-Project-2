#include <exception>
#include <iostream>
#include "exceptii.h"
#include "angajat.h"
#include "manager.h"
#include "programator.h"
#include "tester.h"
#include "meniu.h"

int Angajat::counter = 0;

int main() {
    try {
        Meniu meniu;
        meniu.afiseazaMeniu();
    } catch (const std::exception& e) {
        std::cout << "Eroare critică: " << e.what(  ) << std::endl;
    }
    return 0;
}
