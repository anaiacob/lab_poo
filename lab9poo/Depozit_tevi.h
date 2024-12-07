#include "Depozit.h"

class Depozit_tevi: virtual public Depozit{
protected:
    int nr_tevi;
    double pret_mediu_teava, volum_mediu_teava;
    // spatiu ocupat = suma volumelor tevile depozitate
    // valoare bunuri = suma preturilor tevilor depozitate
public:
    Depozit_tevi()=default;
    Depozit_tevi(int nr, double p, double v):nr_tevi(nr),pret_mediu_teava(p),volum_mediu_teava(v){}
    double getVolum() const override{
        return nr_tevi*volum_mediu_teava;
    }
    void afisare() const override{
        cout<<nr_tevi<<endl;
        cout<<pret_mediu_teava<<" "<<volum_mediu_teava;
        cout<<endl;
        cout<<getVolum()<<endl;
    }
};

