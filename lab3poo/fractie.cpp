#include <iostream>
#include "fractie.h"
#include <stdlib.h>
#include <cstring>
using namespace std;
int Fractie::numar = 0;

Fractie::Fractie(int numarator, int numitor) : a(numarator), b(numitor)
{
    this->a=numarator;
    this->b=numitor;
    numar++;
    nume = new char[20];

    itoa(numar,this->nume+4,10);
    strcpy(this->nume,"var_");
    strcpy(this->nume,this->nume+4);

}
Fractie::Fractie(const Fractie& f):a(f.a),b(f.b)
{
    this->a=f.a;
    this->b=f.b;
    numar++;
    nume = new char[20];
    itoa(numar,this->nume+4,10);
    strcpy(this->nume,"var_");
    strcpy(this->nume,this->nume+4);
}
Fractie::~Fractie()
{
    delete []nume;
}
void Fractie::afisare() const
{
    cout<<a<<"/"<<b<<endl;
}
const Fractie operator-(const Fractie &f1, const Fractie &f2)
{
    return Fractie(f1.a * f2.b - f2.a * f1.b, f1.b * f2.b);
}
