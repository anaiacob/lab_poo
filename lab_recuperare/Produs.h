#include <iostream>
#include <string.h>
#pragma once
using namespace std;
class Produs:public I{
protected:
    char cod[4];
    int pret;
    string descriere;
public:
    Produs()=default;
    Produs(int p, string des,char c[4]):pret(p),descriere(des){
        if(c!=NULL)
        {
            strcpy(cod,c);
        }
    }

    ~Produs();
    virtual int getPret() const
    {
        return pret;
    }
    virtual void afisare() const
    {
        cout<<pret<<" "<<cod<<" "<<descriere<<endl;
    }
};

