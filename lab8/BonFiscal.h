#include "Document.h"
class BonFiscal: public Document {
    protected:
        int ID;
        double suma;
        // Dimensiunea documentului este fixa, egala cu valoarea 12
    public:
        BonFiscal()=default;
        BonFiscal(string den,int id, double s);
        void afiseaza();
};

