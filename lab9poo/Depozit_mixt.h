#include "Depozit_cutii.h"
#include "Depozit_tevi.h"
#include <cstring>

class Depozit_mixt: public Depozit_cutii, public Depozit_tevi {
    char* cauza; //motiv depozitare mixta
    // spatiu ocupat = suma volumelor obiectelor depozitate
    // valoare bunuri = suma preturilor obiectelor depozitate
public:
    Depozit_mixt();
    Depozit_mixt(char*,int,double,double,int, Cutie*);
    Depozit_mixt(const Depozit_mixt&);
    Depozit_mixt& operator=(const Depozit_mixt &);
    double getVolum() const final{
        double s=Depozit_cutii::getVolum()+Depozit_tevi::getVolum();
        return s;
    }
    void afisare() const final{
        cout<<cauza<<endl;

    }
    ~Depozit_mixt();
};


