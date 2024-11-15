#include <iostream>
#include <cstring>
#include "Bilet_eveniment.h"

Bilet_eveniment::Bilet_eveniment()
{
    this->descriere=NULL;
}
Bilet_eveniment::Bilet_eveniment(char* desc, float p, Detalii det): d(det),pret(p)
{
    if(desc!=NULL)
    {
        if(strlen(desc)<5)
            throw length_error("Lungime necorespunzatoare");
        else
        {
            int len=strlen(desc)+1;
            this->descriere=new char[len];
            strcpy(this->descriere,desc);
        }
    }else throw length_error("Lungime necorespunzatoare");

}

Bilet_eveniment::Bilet_eveniment(const Bilet_eveniment& b)
{
    this->pret=b.pret;
    if(b.descriere!=NULL)
    {
        if(strlen(b.descriere)<5)
            throw length_error("Lungime necorespunzatoare");
        else
        {
            int len=strlen(b.descriere)+1;
            this->descriere=new char[len];
            strcpy(this->descriere,b.descriere);
        }
    }
    this->d=b.d;
}
Bilet_eveniment&Bilet_eveniment:: operator=(const Bilet_eveniment& b)
{
    this->pret=b.pret;
    if(b.descriere!=NULL)
    {
        if(strlen(b.descriere)<5)
            throw length_error("Lungime necorespunzatoare");
        else
        {
            int len=strlen(b.descriere)+1;
            this->descriere=new char[len];
            strcpy(this->descriere,b.descriere);
        }
    }
    this->d=b.d;
    return *this;
}
Bilet_eveniment::~Bilet_eveniment()
{
    delete[] this->descriere;
}

ostream& operator<<(ostream& out,  const Bilet_eveniment& det)
{
    out<<"Descriere evenimen:";
    out<<det.descriere<<endl;
    out<<det.d<<endl;
    out<<"Pret:"<<det.pret<<endl;
    return out;
}

istream& operator>>(istream& in,  Bilet_eveniment& deta)
{
    in>>deta.descriere;
    in>>deta.d;
    in>>deta.pret;
    return in;
}
