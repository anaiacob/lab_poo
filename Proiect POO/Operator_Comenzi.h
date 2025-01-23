#include "Angajat.h"
#include "Comanda.h"
#include <vector>
#include <memory>
#include <numeric>
#pragma once
class Operator_Comenzi : public Angajat {
private:
    vector<shared_ptr<Comanda>> comenziProcesate;
    vector<shared_ptr<Comanda>> comenziAsignate;
public:
    Operator_Comenzi(int id, const string& nume, const string& prenume,
                     const string& cnp, const string& dataAngajare);

    void adaugaComanda(const shared_ptr<Comanda>& comanda);
    int getNumarComenziProcesate() const;
    float getValoareTotalaComenzi() const;
    void adaugaComandaAsignata(const shared_ptr<Comanda>& comanda);
    float calculeazaSalariu() const override;
    void afiseazaComenziActive() const;

};

