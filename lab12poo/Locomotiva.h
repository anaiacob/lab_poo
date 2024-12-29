#include "Interfata.h"

class Locomotiva:public Interfata{
protected:
     int valoare;
     int id;
public:
    Locomotiva()=default;
    Locomotiva(int val, int i):valoare(val),id(i){

    }
    void afisare() const override{
        cout<<valoare<<endl;
        cout<<id<<endl;
    }
    int getValoare() const override{
        return valoare;
    }

};

