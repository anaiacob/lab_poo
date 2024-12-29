#include <iostream>
//#include <ofstream>
#include "Imbunatatire.h"
#include "Garnitura.h"
using namespace std;

int main()
{

    vector<string> s(2);
    s.push_back("iure");
    s.push_back("rjei");
    vector<string> r(2);
    r.push_back("ehk");
    r.push_back("hrke");
    vector<string> y(2);
    y.push_back("dsh");
    y.push_back("iow");
    vector<Vagon> vecv(3);
    vecv.push_back(Vagon(s,74));
    vecv.push_back(Vagon(r,84));
    vecv.push_back(Vagon(y,94));
    string ss={"rio"};
    string yy={"euw"};
    string rr={"ekwi"};
    vector<Imbunatatire> veci(3);
    veci.push_back(Imbunatatire(ss,894));
    veci.push_back(Imbunatatire(yy,85));
    veci.push_back(Imbunatatire(rr,904));
    /*Locomotiva l(38,94);
    l.afisare();*/
     //Garnitura g(vecv,veci);
    //g.afisare();
    //cout<<g.getValoare();
   // cout<<endl;
    vector<Interfata*> v;
    v.push_back(new Vagon(s,74));
    v[0]->afisare();
    v.push_back(new Vagon(r,84));
    v.push_back(new Locomotiva(67,92));
    v.push_back(new Locomotiva(783,432));
    v.push_back(new Garnitura(vecv,veci));
   // ofstream f("lab.txt");
    vector<Interfata*>::iterator it;
    int suma=0;
    for(it=v.begin();it!=v.end();it++)
    {
        (*it)->afisare();
        //f<<(*it)->afisare();
       // suma=suma+(*it)->getValoare();
    }
    /*cout<<suma<<endl;
    for(it=v.begin();it!=v.end();it++)
    {
        if((*it)==3)
            v.erase(it);
    }
    int i=2;
    it=v.insert(it,2,Locomotiva(75,384));
    sort(v.begin(),v.end());
    for(it=v.begin();it!=v.end();it++)
    {
        delete *it;
    }
    */
//    f.close();
    return 0;
}
