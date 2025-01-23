#include "Angajat.h"
#include "Manager.h"
#include "Operator_Comenzi.h"
#include "Asistent.h"
#include <vector>
#include <memory>
#include <algorithm>

class gestiuneAngajati {
private:
    vector<shared_ptr<Angajat>> angajati;

public:
    void adaugaAngajat(const shared_ptr<Angajat>& angajat);
    void stergeAngajat(int id);
    void afiseazaAngajati() const;
    void afiseazaAngajat(int id) const;
    void verificaConditii() const;
    void top3AngajatiDupaSalariu() const;

    vector<shared_ptr<Angajat>> getAngajati() const {
        return angajati;
    }
};
