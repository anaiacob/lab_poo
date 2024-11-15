#include <iostream>
using namespace std;
class Detalii {
  char locatie[50]; // ex: “MegaMall_Bucuresti”, “Arene_Cluj-Napoca”, ..
  char data_ora[15]; // “01.10.23_09:30”,  “11.02.24_20:00”
  public:
      Detalii()=default;
      Detalii(char [],char []);
      //~Detalii();

      friend ostream& operator<<(ostream& ,  const Detalii& );
      friend istream& operator>>(istream& ,  Detalii& );
};

