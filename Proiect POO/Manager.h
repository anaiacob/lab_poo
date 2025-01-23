#include "Angajat.h"
#pragma once
class Manager : public Angajat {
public:
    Manager(int id, const string& nume, const string& prenume, const string& cnp, const string& dataAngajare);
    float calculeazaSalariu() const override;
    void afiseazaDetalii() const override;
};
