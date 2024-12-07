#include "Carte.h"

Carte::Carte()
{
    this->pagini=NULL;
    this->nr_pagini=0;
}
Carte::Carte(string den, string* pag, int nr_pag): Document(den),nr_pagini(nr_pag)
{
    this->pagini= new string[nr_pag];
    for(int i=0;i<nr_pag;i++)
    {
        this->pagini[i]=pag[i];
    }
}

Carte::Carte(const Carte& c): Document(c.denumire),nr_pagini(c.nr_pagini)
{
    this->pagini= new string[c.nr_pagini];
    for(int i=0;i<c.nr_pagini;i++)
    {
        this->pagini[i]=c.pagini[i];
    }
}
Carte& Carte::operator=(const Carte &c)
{
    this->denumire=c.denumire;
    this->nr_pagini=c.nr_pagini;
    this->pagini= new string[c.nr_pagini];
    for(int i=0;i<c.nr_pagini;i++)
    {
        this->pagini[i]=c.pagini[i];
    }
}
Carte::~Carte()
{
    delete []pagini;
    pagini=NULL;
}
void Carte::afiseaza()
{
    Document::afiseaza();
    cout<<nr_pagini<<endl;
    for(int i=0;i<nr_pagini;i++)
    {
        cout<<pagini[i]<<endl;
    }
}

