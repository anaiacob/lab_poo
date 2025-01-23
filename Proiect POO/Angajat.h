#include <string>
#include <ctime>
#include <iostream>
#pragma once
using namespace std;

class Angajat {
protected:
    int id;
    string nume;
    string prenume;
    string cnp;
    string dataAngajare;

public:
    Angajat(int id, const string& nume, const string& prenume, const string& cnp, const string& dataAngajare);
    virtual ~Angajat() = default;

    int getID() const;
    string getNume() const;
    string getPrenume() const;
    virtual float calculeazaSalariu() const = 0;
    virtual void afiseazaDetalii() const;

    void modificaNume(const string& nouNume);

    static bool valideazaCNP(const string& cnp);
    static int calculVechime(const string& dataAngajare);
};
