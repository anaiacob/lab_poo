#include <iostream>
using namespace std;

class Cutie{
    int pret;
    double volum;
public:
    Cutie()=default;
    Cutie(int p, double v):pret(p),volum(v){}
    void afisare() const{
        cout<<pret<<endl;
        cout<<volum<<endl;
    }
    int getPret(){return pret;}
    double getvolum(){return volum;}
};

