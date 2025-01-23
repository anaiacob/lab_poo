#include "Comanda.h"

Comanda::Comanda(int id, const vector<shared_ptr<Produs>>& produse, const string& dataPrimire, const string& durataProcesare)
    : id(id), produse(produse), dataPrimire(dataPrimire), durataProcesare(durataProcesare), procesata(false) {
    valoareTotala = calculeazaValoare();
}

double Comanda::calculeazaValoare() const {
    double total = 0.0;
    for (const auto& produs : produse) {
        total += produs->calculeazaPretFinal();
    }
    return total;
}

string Comanda::getDurataProcesare() const {
    return durataProcesare;
}

string Comanda::getDataPrimire() const {
    return dataPrimire;
}

bool Comanda::esteProcesata() const {
    return procesata;
}

void Comanda::seteazaProcesata(bool status) {
    procesata = status;
}

void Comanda::afiseazaDetalii() const {
    cout << "Comanda ID: " << id
              << " | Valoare: " << valoareTotala
              << " RON | Data: " << dataPrimire
              << " | Durata Procesare: " << durataProcesare << "\n";
}

