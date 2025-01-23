#include "Comanda.h"
#include "Operator_Comenzi.h"
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>
class gestiuneComenzi {
private:
    vector<shared_ptr<Operator_Comenzi>> operatori;
    queue<shared_ptr<Comanda>> coadaAsteptare;

public:
    gestiuneComenzi(const vector<shared_ptr<Operator_Comenzi>>& operatori);

    void adaugaComanda(const shared_ptr<Comanda>& comanda);
    void proceseazaComenzi();
   // void afiseazaComenzi()const();
    void afiseazaStatusOperatori() const;
    void angajatCuCeleMaiMulteComenzi() const;
    void top3AngajatiDupaValoareComenzi() const;
};
