#include "Produs_A.h"
#include "Produs_B.h"

class Pachet_Promotional:public I{
    Produs_A pa;
    Produs_B *vec;
    int pb; // atatea produse_b sunt in vec
public:
    Pachet_Promotional()
    {
        pb=0;
        vec=NULL;
    }
    Pachet_Promotional(const Produs_A& a, int pb, Produs_B* v):pa(a),pb(pb)
    {
        if(v!=NULL)
        {
            for(int i=0;i<pb;i++)
               {
                   vec[i]=v[i];
               }
        }
    }
    Pachet_Promotional(const Pachet_Promotional& pachet)
    {
        pa=pachet.pa;
        pb=pachet.pb;
        if(pachet.vec!=NULL)
        {
            for(int i=0;i<pb;i++)
               {
                   vec[i]=pachet.vec[i];
               }
        }
    }
    Pachet_Promotional& operator=(const Pachet_Promotional& pachet)
    {
        pa=pachet.pa;
        pb=pachet.pb;
        if(pachet.vec!=NULL)
        {
            delete[] vec;
            vec=new Produs_B[pb];
            for(int i=0;i<pb;i++)
               {
                   vec[i]=pachet.vec[i];
               }
        }
    }
    ~Pachet_Promotional()
    {
        delete[] vec;
        vec=NULL;
        pb=0;
    }
    float getPret() const
    {
        int s=0;
        s+=pa.getPret();
        for(int i=0;i<pb;i++)
        {
            s+=vec[i].getPret();
        }
        return 0.75*s;
    }
    void afisare() const
    {
        pa.afisare();
        for(int i=0;i<pb;i++)
        {
            vec[i].afisare();
        }
    }
}; // pretul este dat de suma preturilor produselor componente  *75%

