#include "Produs.h"

class Produs_B: public Produs{
     string culoare;
 public:
    Produs_B()=default;
    Produs_B(int p, string des,char c[4],string cul):Produs(p,des,c),culoare(cul)
    {
    }
    int getPret() const override
    {
        return pret;
    }
    void afisare() const override
    {
        Produs::afisare();
        cout<<culoare<<endl;
    }
};

