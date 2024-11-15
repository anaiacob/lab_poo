#include <iostream>
#include <cstring>
using namespace std;
class Companie {
protected:
    char cod_inregistrare[7];
    int an_infiintare;
public:
    Companie()=default;
    Companie(char ci[7],int an):an_infiintare(an)
    {
        strcpy(cod_inregistrare,ci);
    }
    void afisare() const
    {
        cout<<cod_inregistrare;
        cout<<endl;
        cout<<an_infiintare;
        cout<<endl;
    }
    void citire()
    {

        cin>>an_infiintare;

        cin>>cod_inregistrare;

    }
};

