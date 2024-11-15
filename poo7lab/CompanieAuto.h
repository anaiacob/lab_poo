#include "Companie.h"
#include <string>
class CompanieAuto: public Companie {
protected:
     int nr_modele; //2
     string *nume_modele; //ex: model_1, model_2
public:
    ///sigur gresit
    CompanieAuto()
    {
        nume_modele=NULL;
    }
    CompanieAuto(char ci[],int an,int nr, string* s):Companie(ci,an),nr_modele(nr)
    {
        if(s!=NULL)
        {
            nume_modele=new string[nr+1];
            for(int i=0;i<nr;i++)
                nume_modele[i]=s[i];
        }

    }
    CompanieAuto(const CompanieAuto& ca):Companie(ca)
    {
        nr_modele=ca.nr_modele;
        nume_modele=new string[nr_modele];
        for(int i=0;i<ca.nr_modele;i++)
            {
                nume_modele[i]=ca.nume_modele[i];
            }
    }
    ~CompanieAuto()
    {
        delete []nume_modele;
        nume_modele=NULL;
    }
    CompanieAuto& operator=(const CompanieAuto& ca)
    {
        nr_modele=ca.nr_modele;
        delete []nume_modele;
        if(ca.nume_modele!=NULL)
        {
            nume_modele=new string[nr_modele];
            for(int i=0;i<ca.nr_modele;i++)
                {
                    nume_modele[i]=ca.nume_modele[i];
                }
        }
        return* this;
    }
    void afisare() const
    {
        Companie::afisare();
        cout<<nr_modele<<endl;
        for(int i=0;i<nr_modele;i++)
            cout<<nume_modele[i]<<endl;
    }
    ///revenire
    void citire()
    {
        Companie::citire();
        //int nr;
        cin>>nr_modele;
       // string* s;
        nume_modele=new string[nr_modele];
        for(int i=0;i<nr_modele;i++)
            cin>>nume_modele[i];
    }
};

