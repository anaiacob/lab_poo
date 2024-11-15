#include "CompanieAuto.h"
class ReprezentantaAuto: public CompanieAuto {
protected:
    int *nr_masini; //numarul de masini detinute pentru fiecare model:
              //10, 15 (Adica 10 masini de model_1 si 15 model_2)
public:
    ReprezentantaAuto()
    {
        nr_masini=NULL;
    }
    ReprezentantaAuto(char ci[],int an,int nr, string* s,int* nr_m):CompanieAuto(ci,an,nr,s)
    {
        if(nr_m!=NULL)
        {
            nr_masini=new int[nr];
            for(int i=0;i<nr;i++)
            {
                nr_masini[i]=nr_m[i];
            }
        }
    }
    ReprezentantaAuto(const ReprezentantaAuto& ra):CompanieAuto(ra)
    {
        nr_masini=new int[ra.nr_modele];
        for(int i=0;i<ra.nr_modele;i++)
            {
                nr_masini[i]=ra.nr_masini[i];
            }
    }
    ~ReprezentantaAuto()
    {
        delete []nr_masini;
        nr_masini=NULL;
    }
    ReprezentantaAuto& operator=(const ReprezentantaAuto& ra)
    {
        delete []nr_masini;
        if(ra.nr_masini!=NULL)
        {
            nr_masini=new int[ra.nr_modele];
            for(int i=0;i<ra.nr_modele;i++)
            {
                nr_masini[i]=ra.nr_masini[i];
            }
        }
        return* this;
    }
    void afisare() const
    {
        CompanieAuto::afisare();
        for(int i=0;i<CompanieAuto::nr_modele;i++)
            cout<<nr_masini[i]<<" ";
        cout<<endl;
    }
    void citire()
    {
        CompanieAuto::citire();
        nr_masini=new int[nr_modele];
        for(int i=0;i<nr_modele;i++)
            cin>>nr_masini[i];

    }
    friend void sorteaza(ReprezentantaAuto* v, int n)
    {
        cout<<endl;
        cout<<"sortare"<<endl;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(v[i].an_infiintare>v[j].an_infiintare)
                {
                    ReprezentantaAuto aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }
        }
    }
    friend void filtre(ReprezentantaAuto* v, int n)
    {
        cout<<endl;
        cout<<"filtre"<<endl;
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=0;j<v[i].nr_modele;j++)
                s+=v[i].nr_masini[j];
            if(strcmp(v[i].cod_inregistrare,"110231")==0 && v[i].nr_modele>5 && s>10)
            {
                v[i].afisare();
            }

        }
    }
};

