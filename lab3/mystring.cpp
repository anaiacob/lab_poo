#include <iostream>
#include <string.h>
#include "mystring.h"
 using namespace std;

 MyString::MyString()
 {
     this->l=0;
     this->buf=NULL;
 }
 MyString::MyString(char *c)
 {

     if(c!=NULL)
    {this->l=strlen(c);
        this->buf=new char[strlen(c)+1];
         strcpy(this->buf,c);
    }


 }
 MyString::~MyString()
 {
     delete[] buf;
 }
 MyString::MyString(const MyString &cuv)
 {
     this->l=cuv.l;
     delete[] this->buf;
     if(cuv.buf!=NULL)
     {
         this->buf=new char[cuv.l];
         strcpy(this->buf,cuv.buf);
     }
 }
void MyString::citire()
{
    char c[256];
    cin>>c;
    this->l=strlen(c)+1;
    delete[] this->buf;
    if(c!=NULL)
    {
        this->buf=new char[this->l];
        strcpy(this->buf,c);
    }
}
void MyString::afisare() const
{
    cout<<this->l<<" ";
    cout<<this->buf<<endl;
}

MyString& MyString::operator=(const MyString &c)
{
    this->l=c.l;
    delete[] this->buf;
     if(c.buf!=NULL)
    {
        this->buf=new char[c.l];
         strcpy(this->buf,c.buf);
    }
    return *this;
}
const MyString operator+(const MyString &cuv1, const MyString &cuv2)
{
    int nr=strlen(cuv1.buf)+strlen(cuv2.buf)+1;
    char* buff;
    buff=new char[nr];
    if(cuv1.buf!=NULL)
    {
        strcpy(buff,cuv1.buf);
    }
    if(cuv2.buf!=NULL)
    {
        strcat(buff,cuv2.buf);
    }
    return MyString (buff);
}
//nu copiaza cuv
MyString& MyString::operator+=(const MyString &cuv)
{//*this=*this+cuv;
    int nr=cuv.l;
    int cnr=this->l;
    this->l=cnr+nr;
    char c[256];
    if(this->buf!=NULL)
        strcpy(c,this->buf);
    delete[] this->buf;
    this->buf=new char[l];
    strcpy(this->buf,c);
    strcat(buf,cuv.buf)
    if(cuv.buf!=NULL)
    {
        strcpy((this->buf)+cnr,cuv.buf);
    }
    return* this;
}

bool operator==(const MyString &cuv1, const MyString &cuv2)
{
    if(cuv1.l!=cuv2.l) return false;
    else{
        if(strcmp(cuv1.buf,cuv2.buf)==0) return true;
        else return false;
    }
}
bool operator!=(const MyString &cuv1, const MyString &cuv2)
{
     return !(cuv1==cuv2);
    }
}
bool operator<(const MyString &cuv1, const MyString &cuv2)
{
    return (strcmp(cuv1.buf,cuv2.buf)<0)?true:false;

}

bool operator>(const MyString &cuv1, const MyString &cuv2)
{
    return (strcmp(cuv1.buf,cuv2.buf)>0)?true:false;

}
char MyString::getChar(int t) const
{
    if(t>this->l) return '/0';
    else
    {
        return this->buf[t];
    }
}

int MyString::lookFor(char c) const
{
    int nr=0;
    for(int i=0;i<this->l;i++)
    {
        if(this->buf[i]==c)
            nr++;
    }
    return nr;
}
void sorteaza(MyString v[],int nr)
{
    for(int i=0;i<nr-1;i++)
    {
        for(int j=i+1;j<nr;j++)
        {
            if(v[i]>v[j])
            {
                MyString aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}
int numara(MyString v[], int nr, const MyString &cuv2)
{
    int num=0;
    for(int i=0;i<nr;i++)
    {
        if(v[i]==cuv2)
            num++;
    }
    return num;
}
