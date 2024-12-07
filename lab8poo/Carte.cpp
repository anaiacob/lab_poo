#include "Carte.h"
Carte::Carte()
{
    pagini=NULL;
    nr_pagini=0;
}

Carte::Carte(string den, string* pag, int nr_pag):Document(den),nr_pagini(nr_pag)
{
    if(pag!=NULL)
    {
        this->pagini=new string[nr_pag];
        for(int i=0;i<nr_pag;i++)
        {
            this->pagini[i]=pag[i];
        }
    }
    else pagini=NULL;
}

Carte::Carte(const Carte&c):Document(c.denumire),nr_pagini(c.nr_pagini)
{
    this->pagini=new string[c.nr_pagini];
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

void Carte::afisare() const{
    Document::afisare();
    cout<<nr_pagini<<endl;
    for(int i=0;i<nr_pagini;i++)
        cout<<pagini[i]<<endl;
}

int Carte::getDim()
{
    int s=0;
    int i=0;
    while(i<nr_pagini)
    {
        s+=pagini[i].length();
        i++;
    }
    return s;
}
