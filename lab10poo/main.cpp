#include <assert.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <typename T>
class vector
{ int dim;
  T* buf;
  public:
     vector();
     vector(int , T*);
     vector(const vector&);
     vector & operator=(const vector &);
     ~vector();
	 T& operator[](int i);
     int getDim();

	 friend ostream & operator << (ostream & dev, const vector & v)
     {
	    dev << "Vector:" <<endl;
	    dev << "Nr Elem:" << v.dim << endl;
	    if (v.buf!=NULL)
	    for(int i = 0; i < v.dim; i++) {
		   dev << v.buf[i];//am nevoie de op<< pt T
		   if(i < v.dim-1)
		    	dev << ",   ";
		   else
		    	dev << "." << endl;
		}
        dev<<endl;
	    return dev;
     }
     friend bool operator==(const vector<T>&v, const vector<T>&w)
     {
         bool ok=true;
         if(v.dim!=w.dim)
            return !ok;
         else{
            for(int i=0;i<v.dim;i++)
            {
                if(v.buf[i]==w.buf[i])
                    continue;
                else return !ok;
            }
            return ok;
         }
     }
     friend bool operator!=( const vector<T>&v, const vector<T>&w)
     {
         if(v==w) return false;
         else return true;
     }
     void addElem(const T&y)
     {
         if(this->dim!=0)
         {
             int d=2*(this->dim);
             T* g;
             g=new T[this->dim];
             for(int i=0;i<this->dim;i++)
                g[i]=this->buf[i];
             this->dim=d;
             delete []this->buf;
             this->buf=NULL;
             this->buf=new T[this->dim];
             for(int i=0;i<this->dim;i++)
             {
                 if(i%2==1)
                 {
                     this->buf[i]=y;
                 }
                 else if(i%2==0){
                    this->buf[i]=g[i/2];
                 }
             }
         }
         else cout<<"Vectorul are dimensiunea 0."<<endl;
     }

};

template <typename T>
vector<T>::vector( ){
	dim=0;
	buf=NULL;
}

template <typename T>
vector<T>::vector(int d, T*b){
       dim=d;
       if (b==NULL) buf = NULL;
	   else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
            buf[i]=b[i]; //op= in T
        }
     }


template <typename T>
vector<T>::vector(const vector<T>& v){
       dim=v.dim;
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
        }
	 }


template <typename T>
vector<T>::~vector(){
        delete [] buf; //destr in T
}

template <typename T>
vector<T>&  vector<T>::operator=(const vector &v){
       dim=v.dim;
       delete [] buf; //destr in T
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
		}
        return *this;
}

template <typename T>
T& vector<T>::operator[](int i){
      assert ((i>-1 && i<dim));
	  return buf[i];  //constr de copiere in T
}

template <typename T>
int vector<T>::getDim(){
   return dim;
}

class complex
{ double re,im;
public: complex(double r=0,double i=0):re(r),im(i){
        }

        friend ostream& operator<<(ostream &d,complex x){

            d<<x.re<<" j"<<x.im;
            return d;
        }

        friend bool operator==(const complex&a, const complex&b)
         {
             if(a.re==b.re && a.im==b.im) return true;
             else return false;
         }
        friend bool operator!=(const complex&a, const complex&b)
         {
             if(a==b) return false;
             else return true;
         }
};

class S
{
    //string* nume, *prenume;
    string nume, prenume;
public:
    S()=default;
    S(string n, string p):nume(n),prenume(p){

    }
    friend ostream& operator<<(ostream &d, const S& x)
    {
        d<<x.nume<<" ";
        d<<x.prenume<<" ";
        return d;
    }
    friend bool operator==(const S&a, const S&b)
         {
             if(a.nume==b.nume && a.prenume==b.prenume) return true;
             else return false;
         }
    friend bool operator!=(const S&a, const S&b)
         {
             if(a==b) return false;
             else return true;
         }

};

template <typename NC=S, typename Y=int>
class pereche
{
    NC stud1;
    Y nota;
public:
    pereche()=default;
    pereche(const NC& s1, const Y&n)
    {
        stud1=s1;
        nota=n;
    }
    NC getStud()
    {
        return stud1;
    }
    Y getNota()
    {
        return nota;
    }
    friend ostream& operator<<(ostream &d, const pereche<NC,Y>& x)
    {
        d<<x.stud1;
        d<<x.nota;
        return d;
    }
    friend bool operator==(const pereche<NC,Y> &a, const pereche<NC,Y> &b)
         {
             if(a.stud1==b.stud1 && a.nota==b.nota) return true;
             else return false;
         }
    friend bool operator!=(const pereche<NC,Y>&a, const pereche<NC,Y>&b)
         {
             if(a==b) return false;
             else return true;
         }
};

int main(){
	 complex *b=new complex[2];
	 b[0]=complex(1,2);
     b[1]=complex(2,2);
	 vector<complex> v(2,b);
     cout<<v;

	 cout<<v[0];

	 v[1]=complex(5,5);
     cout<<v;

     vector<complex> v1(v);
     cout<<v1;

     v=v1;
     cout<<v;
    string *s=new string[2];
     s[0]={"rufy"};
     s[1]={"gdeu"};
     vector<string> w(2,s);
     cout<<w;
     cout<<w[0];
     w[1]={"ui"};
     cout<<w;
     vector<string> w1(w);
     cout<<w1;
     w=w1;
     cout<<w;
     if(v1!=v) cout<<"da"<<endl;
     else cout<<"nu";
     cout<<v;
     cout<<endl;
     v.addElem(complex(3,1));
     cout<<v;

     cout<<endl;
     cout<<endl;
     cout<<endl;
     pereche<S,int>* q=new pereche<S,int>[3];
     q[0]=pereche<S,int>(S("Ana","Maria"),8);
     q[1]=pereche<S,int>(S("RUI","IIAQ"),9);
     q[2]=pereche<S,int>(S("EIW","IDR"),7);
     vector<pereche<S,int>> p(3,q),p2(p);
     cout<<(p==p2);
     cout<<endl;
     cout<<endl;
     cout<<p2;
     return 0;
}

