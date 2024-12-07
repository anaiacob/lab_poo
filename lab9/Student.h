#include <iostream>
using namespace std;
class Student {
protected:
    double media;
    int nr_restante;
    // daca media > 8.5 si nu are restante atunci are bursa =>
    // venitul unui student pe luna e bursa (=700) sau 0 daca nu are bursa
public:
    Student()=default;
    Student(double m, int nr):media(m),nr_restante(nr){}
    int bursa()
    {
        if(media>8.5) return 700;
        else return 0;
    }
    void afisare()
    {
        cout<<media<<endl;
        cout<<nr_restante<<endl;
        cout<<bursa()<<endl;
    }
};


