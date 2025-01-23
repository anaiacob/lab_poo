#include "Produs.h"
#pragma once
class Disc : public Produs {
protected:
    string casaDiscuri;
    string dataVanzare;
    string trupa;
    string album;

public:
    Disc(int cod, const string& denumire, int stoc, double pretBaza, const string& casaDiscuri, const string& dataVanzare, const string& trupa, const string& album);
    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
    void modificaStoc(int nouStoc) override;
    int getStoc() const override;
};
