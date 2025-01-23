#include "Produs.h"
#include "Articol_Vestimentar.h"
#include "Disc.h"
#include "Disc_Vintage.h"
#include <vector>
#include <memory>

class gestiuneProduse {
private:
    vector<shared_ptr<Produs>> produse;

public:
    void adaugaProdus(const shared_ptr<Produs>& produs);
    void stergeProdus(int cod);
    void afiseazaProduse() const;
    void verificaStoc();
    shared_ptr<Produs> cautaProdus(int cod) {
        for (const auto& produs : produse) {
            if (produs->getCod() == cod) {
                return produs;
            }
        }
        return nullptr;
    }
};

