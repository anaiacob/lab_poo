#include "Depozit_cutii.h"

Depozit_cutii::Depozit_cutii()
{
    this->nr_cutii=0;
    this->cutii=NULL;
}

Depozit_cutii::Depozit_cutii(int nr, Cutie* c):nr_cutii(nr)
{
    this->cutii=new Cutie[nr];
    for(int i=0;i<nr;i++)
    {
        this->cutii[i]=c[i];
        //this->cutii[i].pret=c[i].getPret();
        //this->cutii[i].volum=c[i].getVolum();
    }
}

Depozit_cutii::Depozit_cutii(const Depozit_cutii& c)
{
    this->cutii=new Cutie[c.nr_cutii];
    for(int i=0;i<c.nr_cutii;i++)
    {
        //this->cutii[i].pret=c[i].getPret();
        //this->cutii[i].volum=c[i].getVolum();
        this->cutii[i]=c.cutii[i];
    }
}
Depozit_cutii& Depozit_cutii::operator=(const Depozit_cutii &c)
{
    this->nr_cutii=c.nr_cutii;
    delete []this->cutii;
    this->cutii=new Cutie[c.nr_cutii];
    for(int i=0;i<c.nr_cutii;i++)
    {
        //this->cutii[i].pret=c[i].getPret();
        //this->cutii[i].volum=c[i].getVolum();
        this->cutii[i]=c.cutii[i];
    }
    return *this;
}
/*void Depozit_cutii::afisare() const override
{
    cout<<this->nr_cutii<<endl;
    for(int i=0;i<this->nr_cutii;i++)
    {
        Cutie::this->cutii[i].afisare();
    }
}
double Depozit_cutii::getVolum() const override
{
    double s=0;
    for(int i=0;i<this->nr_cutii;i++)
    {
        s+=this->cutii[i].getVolum();
    }
    return s;
}*/
Depozit_cutii::~Depozit_cutii()
{
    delete []cutii;
    cutii=NULL;
}
