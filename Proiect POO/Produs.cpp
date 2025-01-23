#include "Produs.h"

Produs::Produs(int cod, const string& denumire, int stoc, double pretBaza)
    : cod(cod), denumire(denumire), stoc(stoc), pretBaza(pretBaza) {}

int Produs::getCod() const {
    return cod;
}

void Produs::modificaStoc(int nouStoc) {
    stoc = nouStoc;
}

int Produs::getStoc() const
{
    return stoc;
}
