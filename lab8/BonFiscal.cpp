#include "BonFiscal.h"

BonFiscal::BonFiscal(string den,int id, double s):Document(den),ID(id),suma(s)
{
}
void BonFiscal::afiseaza()
{
    Document::afiseaza();
    cout<<ID<<" "<<suma;
    cout<<endl;
}
