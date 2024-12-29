#include "Locomotiva.h"
#include "Vagon.h"
#include "Imbunatatire.h"
#include <vector>

class Garnitura:public Locomotiva{
    vector<Vagon> vv; // vector cu vagoanele
    vector<Imbunatatire> vi; //vector cu imbunatatiri

// valoare = valoare locomotiva + suma valorilor vagoanelor +suma //valorilor imbunatatirilor
public:
    Garnitura()=default;
    Garnitura(vector<Vagon>& vecv, vector<Imbunatatire>& veci)
    {
        vector<Vagon>::iterator iv;
        vector<Imbunatatire>::iterator ii;
        for(iv=vecv.begin();iv!=vecv.end();iv++)
        {
            vv.push_back(*iv);
        }
        for(ii=veci.begin();ii!=veci.end();ii++)
        {
            vi.push_back(*ii);
        }
    }
    void afisare() const final
    {
        vector<Vagon>::const_iterator iv;
        vector<Imbunatatire>::const_iterator ii;
        for(iv=vv.begin();iv!=vv.end();iv++)
        {
            (*iv).Vagon::afisare();
        }
        for(ii=vi.begin();ii!=vi.end();ii++)
        {
            (*ii).Imbunatatire::afisare();
        }
    }
    int getValoare() const final
    {
        int s=0;
        s+=Locomotiva::getValoare();
        vector<Vagon>::const_iterator iv;
        vector<Imbunatatire>::const_iterator ii;
        for(iv=vv.begin();iv!=vv.end();iv++)
        {
            s+=(*iv).Vagon::getValoare();
        }
        for(ii=vi.begin();ii!=vi.end();ii++)
        {
            s+=(*ii).Imbunatatire::getValoare();
        }
        return s;
    }
};

