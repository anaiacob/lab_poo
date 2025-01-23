#include <iostream>
#include <vector>
#include <algorithm>
#include "Pachet_Promotional.h"
#include "Produs.h"
using namespace std;

int main()
{
    string s={"yirw"};
    string y={"irfwf"};
    string g={"green"};
    string r={"red"};
    Produs p(12,s,"ieyu");
    p.afisare();
    int v[3]={12,11,2021};
    int w[3]={22,3,2023};
    Produs_A pa1(12,s,"rue",v);
    Produs_A pa2(47,y,"rio",w);
    Produs_B pb1(86,y,"fjer",g);
    Produs_B pb2(854,s,"ris",r);
    vector<Produs_B> t(2);
    t.push_back(pb1);
    t.push_back(pb2);
    Pachet_Promotional pp1(pa1,2,t);
    vector<I`*> vec;
    vec.push_back(pa1);
    vec.push_back(pa2);
    vec.push_back(pb1);
    vec.push_back(pb2);
    vec.push_back(pp1);
    vector<Produs*>::iterator it;
    int suma=0;
    //pret final
    for(it=vec.begin();it!=vec.end();it++)
    {
        suma+=(*it)->getPret();
    }
    cout<<suma<<endl;
    sort(vec.begin(),vec.end()[](const Produs& a, const Produs& b) {
            return a->getPret() > b->getPret();
        });
    //afisare date <100
    for(it=vec.begin();it!=vec.end();it++)
    {
        if((*it)->getPret()<100)
            (*it)->afisare();
    }
    //stergere date>1000
    for(it=vec.begin();it!=vec.end();it++)
    {
        if((*it)->getPret()>1000)
            {
                vec.erase(it);
            }
    }
    for(it=vec.begin();it!=vec.end();it++)
    {
        delete *it;
    }
    return 0;
}
