#include "Asistent.h"
#include "utils.h"
Asistent::Asistent(int id, const string& nume, const string& prenume, const string& cnp, const string& dataAngajare)
    : Angajat(id, nume, prenume, cnp, dataAngajare) {}

float Asistent::calculeazaSalariu() const {
    float salariuBaza = 3500 + calculVechime(dataAngajare) * 100;
    int lunaNastere=stoi(cnp.substr(3,2));
    int lunaCurenta=getCurrentMonth();
    if(lunaCurenta==lunaNastere)
    {
        salariuBaza+=100;
    }
    return salariuBaza * 0.75;
}
 void Asistent::afiseazaDetalii() const
 {
     Angajat::afiseazaDetalii();
     cout<<",Salariu: "<<calculeazaSalariu()<<endl;
 }
