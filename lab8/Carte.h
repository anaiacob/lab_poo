#include "Document.h"
class Carte: public Document {
    protected:
        string *pagini;
        int nr_pagini;
        // Dimensiunea documentului este suma nr. de caractere de pe //fiecare pagina
    public:
        Carte();
        Carte(string den, string* pag, int nr_pag);
        Carte(const Carte&);
        Carte& operator=(const Carte &);
        ~Carte();
        void afiseaza();
};

