#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
    /*MyString c=MyString();
    MyString s=MyString("Hello");
    s.afisare();
    c.citire();
    c.afisare();
    //(c+=s).afisare();
    //(c=s).afisare();
    (c+s).afisare();
    if(c==s) cout<<"da";
    else cout<<"NU";
    cout<<endl;
    cout<<s.getChar(1);
    cout<<endl;
    cout<<s.lookFor('l');*/
    /*MyString c=MyString();
    MyString s=MyString("Hello");
    c.citire();
    (c+=s).afisare();*/
    MyString s=MyString("Hello");
    MyString* v;
    int nr;
    cin>>nr;
    v=new MyString[nr];
    for(int i=0;i<nr;i++)
        v[i].citire();
    MyString z=MyString();
    z=v[0];
    //z.afisare();
    for(int i=1;i<nr;i++)
        z+=v[i];
    z.afisare();
    sorteaza(v,nr);
    for(int i=0;i<nr;i++)
        v[i].afisare();
    cout<<numara(v,nr,s);
    return 0;
}
