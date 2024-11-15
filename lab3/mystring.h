class MyString {
    char *buf; //sirul de caractere stocat nu contine spatii
    int l;
public:
    //constr fara param – initializeaza atrib. cu 0 sau NULL
    MyString(); //done
    // constr cu param – primeste un sir de caractere
    MyString(char *); //done
    // constr de copiere
    MyString(const MyString &); //done
    // operator de atribuire
    MyString& operator=(const MyString &); //done
    // destructor
    ~MyString(); //done
    // citeste date pentru un obiect MyString
    void citire(); //done
    // afiseaza datele pentru un obiect MyString
    void afisare() const; //done
    // operator+ concateneaza 2 siruri si salveaza rezultatul intr-un
    // obiect nou de tip MyString pe care il returneaza
    friend const MyString operator+(const MyString &, const MyString &); //done
    // concateneaza 2 siruri si salveaza rezultatul
    // in primul operand a carui adresa o returneaza
    MyString& operator+=(const MyString &); //done
    // verifica daca cele 2 siruri sunt identice
    friend bool operator==(const MyString &, const MyString &); //done
    // verifica daca cele 2 siruri sunt diferite, poate folosi ==
    friend bool operator!=(const MyString &, const MyString &); //done
    // <, <= >, >= ordonare alfanumerica
    friend bool operator<(const MyString &, const MyString &); //done
    friend bool operator>(const MyString &, const MyString &); //done


    //returneaza caracterul de pe pozitia data ca parametru
    char getChar(int) const; //done
    // cauta caracterul dat ca parametru in sir si
    // returneaza numarul de aparitii
    int lookFor(char) const; //done
    friend void sorteaza(MyString v[],int nr);
    friend int numara(MyString v[], int nr, const MyString &cuv2);
    // Vezi cursului 4
    // puteti implementa aceste 3 functii (dar nu e obligatoriu)
    /*
    friend ostream& operator<<(ostream&, const MyString &);
    friend istream& operator>>(istream&, MyString &);
    char& operator[](int);
    */
};
