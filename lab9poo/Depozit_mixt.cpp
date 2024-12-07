#include "Depozit_mixt.h"

Depozit_mixt::Depozit_mixt()
{
    this->cauza=NULL;
}

Depozit_mixt::Depozit_mixt(char* cauze,int nr, double p, double v,int nr_c, Cutie* c):Depozit_tevi(nr,p,v),Depozit_cutii(nr_c,c)
{
    strcpy(this->cauza,cauze);
}
Depozit_mixt::Depozit_mixt(const Depozit_mixt& d):Depozit_cutii(d),Depozit_tevi(d)
{
    this->cauza=new char[strlen(d.cauza)+1];
    strcpy(this->cauza,d.cauza);
    //continue the implementation
}
Depozit_mixt& Depozit_mixt::operator=(const Depozit_mixt &d)
{
    if(this!=&d)
    {
        delete []this->cauza;
        this->cauza=new char[strlen(d.cauza)+1];

    }
    return *this;

}
Depozit_mixt::~Depozit_mixt()
{
    delete []this->cauza;
    this->cauza=NULL;
}
