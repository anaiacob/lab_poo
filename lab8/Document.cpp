#include "Document.h"

Document::Document(string den):denumire(den)
{
}
Document::~Document()
{
}

void Document::afiseaza()
{
    cout<<denumire<<endl;
}
