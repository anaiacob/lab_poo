#include "gestiuneProduse.h"
#include <iostream>
#include <algorithm>

void gestiuneProduse::adaugaProdus(const shared_ptr<Produs>& produs) {
    produse.push_back(produs);
    produs->modificaStoc(produs->getStoc()+1);

}

void gestiuneProduse::stergeProdus(int cod) {
    produse.erase(remove_if(produse.begin(), produse.end(),
        [cod](const shared_ptr<Produs>& p) { return p->getCod() == cod; }),
        produse.end());
}

void gestiuneProduse::afiseazaProduse() const {
    for (const auto& produs : produse) {
        produs->afiseazaDetalii();
    }
}

void gestiuneProduse::verificaStoc() {
    int nrArticoleVestimentare = 0;
    int nrDiscuri = 0;
    int nrDiscuriVintage = 0;

    for (const auto& produs : produse) {
        if (dynamic_cast<Articol_Vestimentar*>(produs.get())) {
            nrArticoleVestimentare++;
        } else if (dynamic_cast<Disc_Vintage*>(produs.get())) {
            nrDiscuriVintage++;
        } else if (dynamic_cast<Disc*>(produs.get())) {
            nrDiscuri++;
        }
    }

    if (nrArticoleVestimentare < 2 || nrDiscuri < 2 || nrDiscuriVintage < 2) {
        cout << "Magazinul NU poate functiona!\n";
        cout << "Stoc insuficient:\n";
        if (nrArticoleVestimentare < 2) cout << "- Articole vestimentare: " << nrArticoleVestimentare << " (minim 2 necesare)\n";
        if (nrDiscuri < 2) cout << "- Discuri: " << nrDiscuri << " (minim 2 necesare)\n";
        if (nrDiscuriVintage < 2) cout << "- Discuri vintage: " << nrDiscuriVintage << " (minim 2 necesare)\n";
    } else {
        cout << "Magazinul poate functiona. Toate categoriile au stoc suficient.\n";
    }
}

