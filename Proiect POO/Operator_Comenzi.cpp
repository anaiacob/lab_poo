#include "Operator_Comenzi.h"
#include "Comanda.h"
#include <iostream>
#include "utils.h"

Operator_Comenzi::Operator_Comenzi(int id, const std::string& nume, const std::string& prenume,
                                   const std::string& cnp, const std::string& dataAngajare)
    : Angajat(id, nume, prenume, cnp, dataAngajare) {}

void Operator_Comenzi::adaugaComanda(const std::shared_ptr<Comanda>& comanda) {
    comenziProcesate.push_back(comanda);
}

int Operator_Comenzi::getNumarComenziProcesate() const {
    return comenziProcesate.size();
}

float Operator_Comenzi::getValoareTotalaComenzi() const {
    return std::accumulate(comenziProcesate.begin(), comenziProcesate.end(), 0.0f,
                           [](float total, const std::shared_ptr<Comanda>& comanda) {
                               return total + comanda->calculeazaValoare();
                           });
}

float Operator_Comenzi::calculeazaSalariu() const {
    float salariuBaza = 3500.0;

    int aniVechime =calculVechime(dataAngajare);

    float salariu = salariuBaza + aniVechime * 100.0;

    float bonusComenzi = getValoareTotalaComenzi() * 0.005;

    int lunaNatere=stoi(cnp.substr(3,2));
    int lunaCurenta=getCurrentMonth();
    if (lunaNatere==lunaCurenta) {
        salariu += 100.0;
    }

    return salariu + bonusComenzi;
}
void Operator_Comenzi::adaugaComandaAsignata(const std::shared_ptr<Comanda>& comanda)
{
    if(comenziAsignate.size()>3)
    {
        comenziAsignate.empty();
        comenziAsignate.push_back(comanda);
    }
    else comenziAsignate.push_back(comanda);
}
void Operator_Comenzi::afiseazaComenziActive() const {
        bool comenziActive = false;
        for (const auto& comanda : comenziAsignate) {
            if (!comanda->esteProcesata()) {
                cout << "Comanda ID: " << comanda->getId() << " - Produse: ";
                for (const auto& produs : comanda->getProduse()) {
                    cout << produs->getDenumire() << " ";
                }
                cout << "\n";
                comenziActive = true;
            }
        }

        if (!comenziActive) {
            cout << "Nu sunt comenzi active.\n";
        }
}
