#include "Disc.h"
#pragma once
class Disc_Vintage : public Disc {
private:
    bool isMint;
    int coeficientRaritate;  // Valori intre 1 și 5

public:
    Disc_Vintage(int cod, const string& denumire, int stoc, double pretBaza, const string& casaDiscuri, const string& dataVanzare, const string& trupa, const string& album, bool isMint, int coeficientRaritate);

    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
    void modificaStoc(int nouStoc) override;
    int getStoc() const override;
};

