#include "gestiuneComenzi.h"

gestiuneComenzi::gestiuneComenzi(const vector<shared_ptr<Operator_Comenzi>>& operatori)
    : operatori(operatori) {}

void gestiuneComenzi::adaugaComanda(const shared_ptr<Comanda>& comanda) {
    if (comanda->calculeazaValoare() < 100.0) {
        cout << "Comanda nu poate fi procesata: valoare prea mica!\n";
        return;
    }
    coadaAsteptare.push(comanda);
}

void gestiuneComenzi::proceseazaComenzi() {
    while (!coadaAsteptare.empty()) {
        bool asignata = false;
        for (auto& operatorComenzi : operatori) {
            if (operatorComenzi->getNumarComenziProcesate() < 3) {
                operatorComenzi->adaugaComanda(coadaAsteptare.front());
                coadaAsteptare.pop();
                asignata = true;
                break;
            }
        }
        if (!asignata) {
            cout << "Toti operatorii sunt ocupati. Comanda a fost plasata in asteptare.\n";
            break;
        }
    }
}


void gestiuneComenzi::afiseazaStatusOperatori() const {
    for (const auto& operatorComenzi : operatori) {
        operatorComenzi->afiseazaComenziActive(); //implementare in Operatori_Comenzi
    }
}

void gestiuneComenzi::angajatCuCeleMaiMulteComenzi() const {
    auto max_it = max_element(operatori.begin(), operatori.end(),
        [](const shared_ptr<Operator_Comenzi>& a, const shared_ptr<Operator_Comenzi>& b) {
            return a->getNumarComenziProcesate() < b->getNumarComenziProcesate();
        });

    if (max_it != operatori.end()) {
        cout << "Operatorul cu cele mai multe comenzi procesate este: "
                  << (*max_it)->getNume() << " " << (*max_it)->getPrenume()
                  << " cu " << (*max_it)->getNumarComenziProcesate() << " comenzi.\n";
    }
}

void gestiuneComenzi::top3AngajatiDupaValoareComenzi() const {
    vector<shared_ptr<Operator_Comenzi>> topOperatori = operatori;

    sort(topOperatori.begin(), topOperatori.end(),
        [](const shared_ptr<Operator_Comenzi>& a, const shared_ptr<Operator_Comenzi>& b) {
            return a->getValoareTotalaComenzi() > b->getValoareTotalaComenzi();
        });

    cout << "Top 3 angajati dupa valoarea comenzilor procesate:\n";
    for (size_t i = 0; i < min(topOperatori.size(), size_t(3)); ++i) {
        cout << i + 1 << ". " << topOperatori[i]->getNume() << " " << topOperatori[i]->getPrenume()
                  << " | Valoare totala: " << topOperatori[i]->getValoareTotalaComenzi() << " RON\n";
    }
}
