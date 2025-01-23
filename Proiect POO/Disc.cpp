#include "Disc.h"

Disc::Disc(int cod, const string& denumire, int stoc, double pretBaza, const string& casaDiscuri, const string& dataVanzare, const string& trupa, const string& album)
    : Produs(cod, denumire, stoc, pretBaza), casaDiscuri(casaDiscuri), dataVanzare(dataVanzare), trupa(trupa), album(album) {}

double Disc::calculeazaPretFinal() const {
    return pretBaza + 5.0;
}
void Disc::modificaStoc(int nouStoc)
{
    stoc=nouStoc;
}
void Disc::afiseazaDetalii() const {
    cout << "Disc - " << denumire << " | Trupa: " << trupa
              << " | Album: " << album << " | Pret Baza: " << pretBaza
              << " RON | Pret Final: " << calculeazaPretFinal() << " RON\n";
}

int Disc::getStoc() const
{
    return stoc;
}
