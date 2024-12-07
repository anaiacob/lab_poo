#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Document {
    protected:
        string denumire;
        // Dimensiunea documentului este 0
    public:
        Document()=default;
        Document(string den);
        virtual~Document();
        virtual void afisare() const;
        virtual int getDim();
};
