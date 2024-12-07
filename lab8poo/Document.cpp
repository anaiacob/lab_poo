#include "Document.h"

Document::Document(string den):denumire(den)
{
}

Document::~Document()
{
}

void Document::afisare() const
{
    cout<<denumire<<endl;
}

int Document::getDim()
{
    return 0;
}
