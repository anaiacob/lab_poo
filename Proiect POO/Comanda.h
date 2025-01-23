#include <vector>
#include <string>
#include <memory>
#include "Produs.h"
#pragma once
class Comanda {
private:
    int id;
    vector<shared_ptr<Produs>> produse;
    double valoareTotala;
    string dataPrimire;
    string durataProcesare;
    bool procesata;

public:
    Comanda(int id, const vector<shared_ptr<Produs>>& produse, const string& dataPrimire, const string& durataProcesare);

    double calculeazaValoare() const;
    string getDurataProcesare() const;
    string getDataPrimire() const;
    vector<shared_ptr<Produs>> getProduse() const
    {
        return produse;
    }
    int getId() const
    {
        return id;
    }
    bool esteProcesata() const;
    void seteazaProcesata(bool status);
    void afiseazaDetalii() const;
};
