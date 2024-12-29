#include <iostream>
#include <string>
#pragma once
using namespace std;

class Imbunatatire {
    string denumire; //AC, tapiterie x
    int valoare;
public:
    Imbunatatire()=default;
    Imbunatatire(string den, int val):denumire(den),valoare(val){

    }
    void afisare() const {
        cout<<denumire<<endl;
        cout<<valoare<<endl;
    }
    int getValoare() const
    {
        return valoare;
    }
};


