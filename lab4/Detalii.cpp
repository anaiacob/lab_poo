#include <iostream>
#include <cstring>
#include "Detalii.h"
using namespace std;

Detalii::Detalii(char loc[],char time[])
{
    if(loc!=NULL)
    {
        strcpy(this->locatie,loc);
    }
    if(time!=NULL)
    {
        if(strlen(time)!=8 && strlen(time)!=14)
        {
            throw invalid_argument("Nu este lungimea corespunzatoare");
        }
        else{
            strcpy(this->data_ora,time);
        }
    }
}

ostream& operator<<(ostream& out,  const Detalii& det)
{
    out<<"Detaliile sunt:"<<endl;
    out<<"Locatie: "<<det.locatie;
    out<<endl;
    out<<"Data si ora: "<<det.data_ora;
    out<<endl;
    return out;
}

istream& operator>>(istream& in,  Detalii& deta)
{
    in>>deta.locatie;
    in>>deta.data_ora;
    if(strlen(deta.data_ora)!=8 && strlen(deta.data_ora)!=14)
        {
            throw invalid_argument("Nu este lungimea corespunzatoare");
        }
    return in;
}
