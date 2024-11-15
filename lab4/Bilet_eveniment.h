#include <iostream>
#include "Detalii.h"
using namespace std;
class Bilet_eveniment {
   char* descriere; // ex: "Nume_film", “Nume_trupa”, “Nume_festival”,..
   Detalii d; //locatie, data ora desfasurare
   float pret; // 185.5
   public:
       Bilet_eveniment();
       Bilet_eveniment(char*,float,Detalii);
       Bilet_eveniment(const Bilet_eveniment&); //pointer
       Bilet_eveniment& operator=(const Bilet_eveniment&);//pointer
       ~Bilet_eveniment();//pointer
       friend ostream& operator<<(ostream& ,  const Bilet_eveniment& );
       friend istream& operator>>(istream& ,  Bilet_eveniment& );

};

