#include <iostream>
#include <cstring>
using namespace std;
class Bon {
private:
    char tip[10]; //masa, vacanta, transport
    int valoare;
public:
    Bon()=default;
    Bon(char t[10],int val):valoare(val){
        strcpy(tip,t);
    }
    void afisare()
    {
        cout<<tip;
        cout<<endl;
        cout<<valoare<<endl;
    }
    //virtual ~Bon();
};


