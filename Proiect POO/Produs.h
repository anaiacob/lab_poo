#include <string>
#include <iostream>
#pragma once
using namespace std;

class Produs {
protected:
    int cod;
    string denumire;
    int stoc;
    double pretBaza;

public:
    Produs(int cod, const string& denumire, int stoc, double pretBaza);
    virtual ~Produs() = default;

    int getCod() const;
    virtual int getStoc() const;
    virtual double calculeazaPretFinal() const = 0;
    virtual void afiseazaDetalii() const = 0;

    virtual void modificaStoc(int nouStoc);
};

