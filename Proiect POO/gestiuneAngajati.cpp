#include "gestiuneAngajati.h"

void gestiuneAngajati::adaugaAngajat(const shared_ptr<Angajat>& angajat) {
    angajati.push_back(angajat);
}

void gestiuneAngajati::stergeAngajat(int id) {
    angajati.erase(remove_if(angajati.begin(), angajati.end(),
                                  [id](const shared_ptr<Angajat>& a) { return a->getID() == id; }),
                   angajati.end());
}

void gestiuneAngajati::afiseazaAngajati() const {
    for (const auto& angajat : angajati) {
        angajat->afiseazaDetalii();
    }
}

void gestiuneAngajati::afiseazaAngajat(int id) const
{
    for (const auto& angajat : angajati) {
        if(angajat->getID()==id)
            angajat->afiseazaDetalii();
    }
}

void gestiuneAngajati::verificaConditii() const {
    int manageri = 0, operatori = 0, asistenti = 0;

    for (const auto& angajat : angajati) {
        if (dynamic_cast<Manager*>(angajat.get())) manageri++;
        else if (dynamic_cast<Operator_Comenzi*>(angajat.get())) operatori++;
        else if (dynamic_cast<Asistent*>(angajat.get())) asistenti++;
    }

    if (manageri == 0 || operatori < 3 || asistenti == 0) {
        cout << "Magazinul NU poate functiona! Conditii nesatisfacute.\n";
    } else {
        cout << "Magazinul poate functiona.\n";
    }
}

void gestiuneAngajati::top3AngajatiDupaSalariu() const {
    vector<shared_ptr<Angajat>> topAngajati = angajati;

    sort(topAngajati.begin(), topAngajati.end(),
        [](const shared_ptr<Angajat>& a, const shared_ptr<Angajat>& b) {
            return a->calculeazaSalariu() > b->calculeazaSalariu();
        });

    cout << "Top 3 angajati cu cel mai mare salariu in luna curenta:\n";
    for (size_t i = 0; i < min(topAngajati.size(), size_t(3)); ++i) {
        cout << i + 1 << ". " << topAngajati[i]->getNume() << " " << topAngajati[i]->getPrenume()
                  << " | Salariu: " << topAngajati[i]->calculeazaSalariu() << " RON\n";
    }
}
