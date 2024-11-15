class Garantie {
  int nr_luni;  // are valoare min 3 si max 36
  char cod_service[10]; // codul firmei care asigura service-ul are min 2
                        //si max 9 caractere
public:
    Garantie(int,char*);
    Garantie(const Garantie&);
    Garantie& operator=(const Garantie&);
    ~Garantie();
    int getMonth() const;
    const char* getCod() const;
    friend ostream& operator<<(ostream&,const Garantie&);
};

