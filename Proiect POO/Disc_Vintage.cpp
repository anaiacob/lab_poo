#include "Disc_Vintage.h"

Disc_Vintage::Disc_Vintage(int cod, const std::string& denumire, int stoc, double pretBaza, const std::string& casaDiscuri, const std::string& dataVanzare, const std::string& trupa, const std::string& album, bool isMint, int coeficientRaritate)
    : Disc(cod, denumire, stoc, pretBaza, casaDiscuri, dataVanzare, trupa, album), isMint(isMint), coeficientRaritate(coeficientRaritate) {}

double Disc_Vintage::calculeazaPretFinal() const {
    return pretBaza + 5.0 + 15.0 * coeficientRaritate;
}
void Disc_Vintage::modificaStoc(int nouStoc)
{
    stoc=nouStoc;
}
void Disc_Vintage::afiseazaDetalii() const {
    std::cout << "Disc Vintage - " << denumire << " | Trupa: " << trupa
              << " | Album: " << album
              << " | Casa Discuri: " << casaDiscuri
              << " | Data Vanzare: " << dataVanzare
              << " | Mint: " << (isMint ? "Da" : "Nu")
              << " | Coeficient Raritate: " << coeficientRaritate
              << " | Pret Baza: " << pretBaza << " RON"
              << " | Pret Final: " << calculeazaPretFinal() << " RON\n";
}

int Disc_Vintage::getStoc() const
{
    return stoc;
}
