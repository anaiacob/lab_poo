#include "Produs.h"
#pragma once
class Articol_Vestimentar : public Produs {
private:
    string culoare;
    string marca;

public:
    Articol_Vestimentar(int cod, const string& denumire, int stoc, double pretBaza, const string& culoare, const string& marca);
    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
    void modificaStoc(int nouStoc) override;
    int getStoc() const override;
};

