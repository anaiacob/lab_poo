#include "Cutie.h"
#include "Depozit.h"

class Depozit_cutii:virtual public Depozit{
protected:
    int nr_cutii; //numar cutii depozitate
    Cutie* cutii; //cutiile depozitate
    // spatiu ocupat = suma volumelor cutiilor depozitate
    // valoare bunuri = suma preturilor cutiilor depozitate
public:
    Depozit_cutii();
    Depozit_cutii(int, Cutie*);
    Depozit_cutii(const Depozit_cutii&);
    Depozit_cutii& operator=(const Depozit_cutii &);
    void afisare() const override
    {
        cout<<nr_cutii<<endl;
        for(int i=0;i<nr_cutii;i++)
        {
            cout<<cutii[i].getPret()<<" "<<cutii[i].getvolum()<<endl;
        }
    }
    double getVolum() const override
    {
        double s=0;
        for(int i=0;i<this->nr_cutii;i++)
        {
            s+=this->cutii[i].getvolum();
        }
        return s;
    }
    ~Depozit_cutii();
};

