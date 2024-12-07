#include <iostream>
#include "BonFiscal.h"
#include "Carte.h"
using namespace std;

int main()
{
    string s={"cd"};
    string* g;
    g=new string[2];
    for(int i=0;i<2;i++)
    {
        g[i]="a";
    }
    Document d(s);
    d.afiseaza();
    BonFiscal b(s,12,20);
    b.afiseaza();
    Carte c(s,g,2);
    c.afiseaza();

    //Document** v=new Document[6];
    //v[0]=
    return 0;
}
