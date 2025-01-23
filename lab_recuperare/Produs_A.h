#include "Produs.h"

class Produs_A: public Produs{
    int data_expirare[3];//zz,ll,aaaa
public:
    Produs_A()=default;
    Produs_A(int p, string des,char c[4],int data[3]):Produs(p,des,c)
    {
        for(int i=0;i<3;i++)
        {
            data_expirare[i]=data[i];
        }
    }
    int getPret() const override
    {
        return pret;
    }
    void afisare() const override
    {
        Produs::afisare();
        for(int i=0;i<3;i++)
        {
            cout<<data_expirare[i]<<".";
        }
        cout<<endl;
    }
};

