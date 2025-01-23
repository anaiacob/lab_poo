#include "Articol_Vestimentar.h"

Articol_Vestimentar::Articol_Vestimentar(int cod, const string& denumire, int stoc, double pretBaza, const string& culoare, const string& marca)
    : Produs(cod, denumire, stoc, pretBaza), culoare(culoare), marca(marca) {}

double Articol_Vestimentar::calculeazaPretFinal() const {
    return pretBaza + 20.00;
}
void Articol_Vestimentar::modificaStoc(int nouStoc)
{
    stoc=nouStoc;
}
void Articol_Vestimentar::afiseazaDetalii() const {
    cout << "Articol Vestimentar - " << denumire << " | Marca: " << marca
              << " | Culoare: " << culoare << " | Pret Baza: " << pretBaza
              << " RON | Pret Final: " << calculeazaPretFinal() << " RON\n";
}

int Articol_Vestimentar::getStoc() const
{
    return stoc;
}
