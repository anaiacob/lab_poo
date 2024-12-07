#include "BonFiscal.h"

BonFiscal::BonFiscal(string den,int id, double s):Document(den),ID(id),suma(s)
{
}
void BonFiscal::afisare() const
{
    Document::afisare();
    cout<<ID<<" "<<suma<<endl;
}
int BonFiscal::getDim(){
    return 12;
}
