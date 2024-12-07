#include <iostream>
#include "Bon.h"
#include "Student.h"
using namespace std;

int main()
{
    char t[10]="masa";
    Bon b(t,10);
    b.afisare();
    Student s1(9,0);
    Student s2(7,2);
    s1.afisare();
    s2.afisare();

    return 0;
}
