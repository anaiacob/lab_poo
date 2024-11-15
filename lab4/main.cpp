#include "Bilet_eveniment.h"
using namespace std;

/*void afis_desc(char loc[50],char data[8],const Bilet_eveniment& b)
{
    char d[10], o[8];
    strncpy(d,b.d.data_ora,8);
    strncpy(o,b.d.data_ora+8,4);
    if(strcmp(b.d.locatie,loc)==0 && strcmp(d,data)==0 && strcmp(0,"20:00")>0)
        cout<<b.descriere;
}*/
int main()
{
    Detalii d2;
    try{
        Detalii d1("MegaMall_Bucuresti","01.10.23_09:30");
       // cout<<d1;
        //cin>>d1;
        d2=d1;
    }
    catch(const invalid_argument& e)
    {
        cout<<e.what();
    }

    try{
        Bilet_eveniment b1("Nume_film",180,d2);
        cout<<endl<<b1;
    }
    catch(const length_error& e)
    {
        cout<<e.what();
    }
    int n;
    cin>>n;
    Bilet_eveniment* v;
    v=new Bilet_eveniment[n];
    for(int i=0;i<n;i++){
        //cin>>v[i];
        try{

        }
    }

    for(int i=0;i<n;i++)
        afis_desc("MegaMall_Bucuresti","01.10.23",v[i]);
    return 0;
}
