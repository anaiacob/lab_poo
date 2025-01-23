#include "Angajat.h"
#include "utils.h"


Angajat::Angajat(int id, const string& nume, const string& prenume, const string& cnp, const string& dataAngajare)
    : id(id), nume(nume), prenume(prenume), cnp(cnp), dataAngajare(dataAngajare)
{
    if (valideazaCNP(cnp)==false) throw invalid_argument("CNP invalid!");
    if (nume.length() < 3 || nume.length() > 30 || prenume.length() < 3 || prenume.length() > 30)
        throw invalid_argument("Nume sau prenume invalid!");
}

int Angajat::getID() const {
    return id;
}

string Angajat::getNume() const{
    return nume;
}
string Angajat::getPrenume() const{
    return prenume;
}
void Angajat::modificaNume(const string& nouNume) {
    if (nouNume.length() >= 3 && nouNume.length() <= 30) {
        nume = nouNume;
    } else {
        throw invalid_argument("Nume invalid!");
    }
}

void Angajat::afiseazaDetalii() const {
    cout << "ID: " << id << ", Nume: " << nume << ", Prenume: " << prenume
              << ", CNP: " << cnp << ", Data Angajare: " << dataAngajare << " ";
}

bool Angajat::valideazaCNP(const string& cnp) {
    if (cnp.length() != 13) {
            cout<<"cifre putine"<<endl;
        return false;
    }

    for (char caracter : cnp) {
        if (!isdigit(caracter)) {
            return false;
        }
    }
    int sex = stoi(cnp.substr(0,1));
    if (sex < 1 || sex > 8) {
            cout<<"sex gresit"<<endl;
        return false;
    }

    int anul = stoi(cnp.substr(1, 2));
    int luna = stoi(cnp.substr(3, 2));
    int ziua = stoi(cnp.substr(5, 2));

    int secol;
    if (sex == 1 || sex == 2) secol = 1900;
    else if (sex == 3 || sex == 4) secol = 1800;
    else if (sex == 5 || sex == 6) secol = 2000;
    else if (sex == 7 || sex == 8) secol = 2000;
    anul += secol;

    if(anul<1950 || anul>2007)
    {
        cout<<"Iesire din intervalul de varsta."<<endl;
        return false;
    }
    if(luna<1 || luna>12)
    {
        cout<<"luna gresita"<<endl;
        return false;
    }
    if(anul%4==0 && luna==2 && (ziua<1 || ziua>29))
    {
        cout<<"zi gresita"<<endl;
        return false;
    }
    if(anul%4!=0 && luna==2 && (ziua<1 || ziua>28))
    {
        cout<<"zi gresita"<<endl;
        return false;
    }
    if((luna==4 ||luna==6 || luna==9 || luna==11) && (ziua<1 || ziua>30))
       {
           cout<<"zi gresita"<<endl;
           return false;

       }
    if((luna==1 ||luna==3 || luna==5 || luna==7 || luna==8 || luna==10 || luna==12) && (ziua<1 || ziua>31))
       {
           cout<<"zi gresita"<<endl;
           return false;

       }
    int judet = stoi(cnp.substr(7, 2));
    if ((judet < 1 || judet > 52) && judet != 99) {
            cout<<"judet gresit"<<endl;
        return false;
    }

    const int control[] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9}; //279146358279
    int suma = 0;
    for (int i = 0; i < 12; ++i) {
        suma += stoi(cnp.substr(i,1)) * control[i];
        //cout<<stoi(cnp.substr(i,1))<<endl;
    }
    //cout<<suma<<endl;
    int cifra_control = suma % 11;
    if (cifra_control == 10) cifra_control = 1;

    if (cifra_control != stoi(cnp.substr(12,1))) {
            //cout<<stoi(cnp.substr(12,1))<<endl;
            cout<<"cifra control gresita"<<endl;
        return false;
    }
    return true;
}


int Angajat::calculVechime(const string& dataAngajare) {
    int an_curent=getCurrentYear();
    int ani_vechime=an_curent-stoi(dataAngajare.substr(0,4));
    return ani_vechime;
}
