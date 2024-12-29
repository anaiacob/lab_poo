#include "Interfata.h"
#include <vector>
#include <string>
class Vagon:public Interfata{
    vector<string> caracteristici; //calatori/marfa, nr_locuri/tonaj
    int pret_de_baza;
    //valoare= pret_de_baza
public:
    Vagon()=default;
    Vagon(vector<string> c, int pret):pret_de_baza(pret)
    {
        vector<string>::iterator it;
        for(it=c.begin();it!=c.end();it++)
        {
            caracteristici.push_back(*it);
        }
    }
    void afisare() const override{
        vector<string>::const_iterator it;
        for(it=caracteristici.begin();it!=caracteristici.end();it++)
        {
            cout<<*it<<endl;
        }
        cout<<pret_de_baza<<endl;
    }
    int getValoare() const override
    {
        return pret_de_baza;
    }
};

