#include <iostream>
#include "ReprezentantaAuto.h"
using namespace std;

int main()
{
    /*Companie c("1234",2000);
    c.afisare();
    Companie d;
    d.citire();
    string s[2]={"model_1", "model_2"};
    CompanieAuto h("1234",1002,2,s);
    h.afisare();
    CompanieAuto i;
    i.citire();
    h=i;
    h.afisare();*/
   /* int nr_m[2]={10, 15};
    string s[2]={"model_1", "model_2"};
    ReprezentantaAuto g("1234",1002,2,s,nr_m);
    //g.afisare();
    ReprezentantaAuto f;
    f.citire();
    g=f;
    g.afisare();*/
    ReprezentantaAuto* vec;
    int n;
    cin>>n;
    vec=new ReprezentantaAuto[n];
    for(int i=0;i<n;i++)
    {
        cout<<"index:"<<i<<endl;
        vec[i].citire();
    }
    sorteaza(vec,n);
    for(int i=0;i<n;i++)
    {
        cout<<"index:"<<i<<endl;
        vec[i].afisare();
    }
    filtre(vec,n);
    return 0;
}
