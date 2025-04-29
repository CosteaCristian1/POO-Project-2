#include <exception>
#include <cstring>

class ExceptieAngajat : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Eroare legata de angajat.";
    }
};

class IdInvalidException : public ExceptieAngajat {
public:
    const char* what() const noexcept override {
        return "ID-ul angajatului este invalid.";
    }
};

class DateIncompleteException : public ExceptieAngajat {
public:
    const char* what() const noexcept override {
        return "Datele introduse pentru angajat sunt incomplete.";
    }
};

class FunctieNecunoscutaException : public ExceptieAngajat {
public:
    const char* what() const noexcept override {
        return "Functia introdusa pentru angajat este necunoscuta.";
    }
};