#include <iostream>
#include "Depozit_mixt.h"
using namespace std;

int main()
{
    Cutie c1(12,2.5), c2(22, 2);
    Cutie c[2];
    c[0]=c1;
    c[1]=c2;
    Depozit_cutii dc(2,c);
    dc.afisare();
    cout<<dc.getVolum()<<endl;
    Depozit_tevi t(3,22.2,5);
    t.afisare();
    char* cauza=new char[100];
    strcpy(cauza,"supraaglomerare");
    Depozit_mixt dm(cauza,5,6,34,2,c);
    dm.afisare();
    /*Depozit** v= new Depozit*[5];
    v[0]=new Depozit_cutii(2,c);
    v[1]=new Depozit_tevi(3,22.2,5);
    v[3]=new Depozit_mixt((cauza,5,6,34,2,c);*/
    return 0;
}
