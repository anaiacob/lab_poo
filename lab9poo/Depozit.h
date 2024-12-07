#include <iostream>
#pragma once
using namespace std;

class Depozit{
public:
    virtual double getVolum() const =0;
    virtual void afisare() const =0;
    virtual ~Depozit()=0;
};
