class Fractie {
    static int numar; //initializare in Fractie.cpp: int Fractie::numar=0;
    char* nume; //var_1, …, var_14, etc
    int a; // numarator
    int b; // numitor
public:
    // constructor cu parametrii impliciti - seteaza valorile pentru a si
    // b folosind parametrii, numar este incrementat, iar numele este
    // format din sirul “var_” si numar convertit la char* cu fctia itoa
    // din biblioteca stdlib.h
    Fractie(int = 0, int = 1);
    // constructor de copiere – copiaza valorile pentru a si b, numele este
    //format din sirul “var_” si numar incrementat si convertit la char*
    Fractie(const Fractie &);
    // se intoarce referinta la obiectul modificat pt a putea face op
    // de genul : int x,y,z,w ;  x=(y=(z=(w=4)));  (asoc. la dreapta)
    // nu se modifica nume
    Fractie &operator=(const Fractie &);
    // elibereaza spatiul ocupat de un obiect
    ~Fractie();
    // afiseaza fractia sub forma: nume: a/b
    void afisare() const;
    // retuneaza a / b
    double getValoare() const;
    // supradefinire operator binar scadere; operanzii sunt declarati const
    // ca sa nu poata fi modificati; se returneaza un obiect constant
    // ca sa nu pot sa fac operatii de tipul (x-y) = Fractie(1, 2);
    // caz in care atribuirea ar putea sa aiba loc, dar pierdem rezultatul
    // rezultatul e un nou obiect cu nume setat la constructie
    // Ex.: fr = f1 - f2
    friend const Fractie operator-(const Fractie &, const Fractie &);
    // supradefinire operator unar - . Ex.: d = -e;
    const Fractie operator-();
    friend const Fractie operator*(const Fractie &, const Fractie &);
    // supradefinire operator -= intoarce referinta
    // la Fractie pt a putea face operatii ca : int m;  (m-=5)-=3;
    Fractie& operator-=(const Fractie &);
    Fractie& operator*=(const Fractie &);
    // supradefinire operator de testare egalitate   (2/3 == 4/6)
    friend bool operator==(const Fractie &, const Fractie &);
    // supradefinire operator diferit - pot sa folosesc in implementare
    // operatorul == implementat anterior
    friend bool operator!=(const Fractie &, const Fractie &);
    friend bool operator>(const Fractie &, const Fractie &);
    friend bool operator>=(const Fractie &, const Fractie &);
     // operator<< si operator>> vor fi implementati optional
    // friend ostream& operator<<(ostream &, const Fractie &);
    // friend istream& operator>>(istream &, Fractie &);
};

