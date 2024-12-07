#include "Carte.h"
#include "BonFiscal.h"
void sortare(Document** v, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i]->getDim()>v[j]->getDim())
            {
                Document* aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}
int main()
{
    string s={"fh"};
    Document d(s);
    d.afisare();
    BonFiscal b(s,12,20);
    b.afisare();
    string g[2]={"hdj","eyur"},h[3]={"hdj","eyur","lfkfuire"};
    Carte c(s,g,2);
    c.afisare();
    cout<<d.getDim()<<" "<<b.getDim()<<" "<<c.getDim()<<endl;
    Document** v=new Document*[5];
    v[0]=new Carte("gh",g,2);
    v[1]=new Carte("riwp",h,3);
    v[2]=new Document("hdj");
    v[3]=new BonFiscal("iowe",34,483);
    v[4]=new BonFiscal("usdie",738,10);
    sortare(v,5);
    for(int i=0;i<5;i++)
        {
            v[i]->afisare();
            cout<<endl;
        }
    for(int i=0;i<5;i++)
        delete v[i];
    delete []v;
    return 0;
}
