#include <iostream>
#include <string.h>
using namespace std;

class Track
{
    string nume;
    static int pozitie;
    int durata;
public:
    Track()=default;
    Track(string n, int d);
    int getDurata()
    {
        return durata;
    }
    int getPos()
    {
        return pozitie;
    }
    string getNume()
    {
        return nume;
    }
    bool operator<(const Track& t) const {
        return pozitie < t.pozitie;
    }
};
