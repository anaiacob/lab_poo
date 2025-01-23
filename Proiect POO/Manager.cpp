#include "Manager.h"

Manager::Manager(int id, const string& nume, const string& prenume, const string& cnp, const string& dataAngajare)
    : Angajat(id, nume, prenume, cnp, dataAngajare) {}

float Manager::calculeazaSalariu() const {
    return (3500 + calculVechime(dataAngajare) * 100) * 1.25;
}

void Manager::afiseazaDetalii() const
{
    Angajat::afiseazaDetalii();
    cout<<",Salariu: "<<calculeazaSalariu()<<endl;
}
