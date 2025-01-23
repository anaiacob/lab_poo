#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "gestiuneAngajati.h"
#include "gestiuneProduse.h"
#include "gestiuneComenzi.h"
#include "Manager.h"
#include "Operator_Comenzi.h"
#include "Asistent.h"
#include "Articol_Vestimentar.h"
#include "Disc.h"
#include "Disc_Vintage.h"

using namespace std;

void adaugaAngajati(gestiuneAngajati& gestiune) {
    gestiune.adaugaAngajat(make_shared<Manager>(1, "Popescu", "Ion", "1980101123452", "2015-05-01"));

    gestiune.adaugaAngajat(make_shared<Operator_Comenzi>(2, "Ionescu", "Maria", "2960509123454", "2018-06-15"));
    gestiune.adaugaAngajat(make_shared<Operator_Comenzi>(3, "Georgescu", "Andrei", "1970303123457", "2017-02-10"));
    gestiune.adaugaAngajat(make_shared<Operator_Comenzi>(4, "Dumitru", "Elena", "2930405123455", "2020-01-20"));
    gestiune.adaugaAngajat(make_shared<Operator_Comenzi>(5, "Dumitru", "Elena", "6041111420077", "2020-01-20"));

    gestiune.adaugaAngajat(make_shared<Asistent>(6, "Stoica", "Mihai", "1990805123457", "2021-04-18"));
}

void adaugaProduse(gestiuneProduse& gestProduse) {
    gestProduse.adaugaProdus(make_shared<Articol_Vestimentar>(101, "Tricou Rock", 50, 50.0, "Negru", "RockStore"));
    gestProduse.adaugaProdus(make_shared<Disc>(102, "Album CD", 30, 70.0, "Universal", "2020-01-01", "Trupa X", "Album Y"));
    gestProduse.adaugaProdus(make_shared<Disc_Vintage>(103, "Vinil Vintage", 10, 100.0, "EMI", "1980-05-05", "Trupa Z", "Classic Album", true, 4));
}

void adaugaComenzi(gestiuneComenzi& gestComenzi, gestiuneProduse& gestProduse, gestiuneAngajati& gestAngajati) {
    vector<shared_ptr<Produs>> produseComanda1 = { gestProduse.cautaProdus(101), gestProduse.cautaProdus(89) };
    gestComenzi.adaugaComanda(make_shared<Comanda>(1001, produseComanda1, "2025-01-01", "2 zile"));

    vector<shared_ptr<Produs>> produseComanda2 = { gestProduse.cautaProdus(102) };
    gestComenzi.adaugaComanda(make_shared<Comanda>(1002, produseComanda2, "2025-01-02", "3 zile"));
}

void genereazaRapoarte(const gestiuneAngajati& gestAngajati, const gestiuneComenzi& gestComenzi) {
    cout << "Raport Angajat cu cele mai multe comenzi procesate:\n";
    for (const auto& angajat : gestAngajati.getAngajati()) {
        if (auto operatorComenzi = dynamic_cast<Operator_Comenzi*>(angajat.get())) {
            cout << angajat->getNume() << " " << angajat->getPrenume() << ": "
                 << operatorComenzi->getNumarComenziProcesate() << " comenzi procesate\n";
        }
    }

    cout << "\nRaport Angajat cu cele mai valoroase comenzi:\n";
    for (const auto& angajat : gestAngajati.getAngajati()) {
        if (auto operatorComenzi = dynamic_cast<Operator_Comenzi*>(angajat.get())) {
            cout << angajat->getNume() << " " << angajat->getPrenume() << ": "
                 << operatorComenzi->getValoareTotalaComenzi() << " RON\n";
        }
    }
    cout << "\nRaport Angajați cu cele mai mari salarii:\n";
    /*for (const auto& angajat : gestAngajati.getAngajati()) {
        cout << angajat->getNume() << " " << angajat->getPrenume() << ": Salariul: " << angajat->calculeazaSalariu() << " RON\n";
    }*/
    gestAngajati.top3AngajatiDupaSalariu();
}

vector<Angajat> citesteAngajati(const string& filename) {
    vector<Angajat> angajati;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string nume, prenume;
        double salariu;
        ss >> id >> nume >> prenume >> cnp>>dataAngajare>>functie;
        angajati.push_back(Angajat(id, nume, prenume, cnp,dataAngajare));
    }
    return angajati;
}

vector<Produs> citesteProduse(const string& filename) {
    vector<Produs> produse;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nume;
        double pret;
        int stoc;
        ss>>id >> nume>> stoc>> pretBaza;
        produse.push_back(Produs(id, nume, stoc, pretBaza));
    }
    return produse;
}

void scrieRaportCSV(const string& filename, const gestiuneAngajati& gestAngajati, const gestiuneComenzi& gestComenzi) {
    ofstream file(filename);
    file << "ID, Nume, Prenume, Salariu\n";
    file << "Raport Angajat cu cele mai multe comenzi procesate:\n";
    for (const auto& angajat : gestAngajati.getAngajati()) {
        if (auto operatorComenzi = dynamic_cast<Operator_Comenzi*>(angajat.get())) {
            file << angajat->getNume() << " " << angajat->getPrenume() << ": "
                 << operatorComenzi->getNumarComenziProcesate() << " comenzi procesate\n";
        }
    }

    file << "\nRaport Angajat cu cele mai valoroase comenzi:\n";
    for (const auto& angajat : gestAngajati.getAngajati()) {
        if (auto operatorComenzi = dynamic_cast<Operator_Comenzi*>(angajat.get())) {
            file << angajat->getNume() << " " << angajat->getPrenume() << ": "
                 << operatorComenzi->getValoareTotalaComenzi() << " RON\n";
        }
    }
    file << "\nRaport Angajați cu cele mai mari salarii:\n";
    for (const auto& angajat : gestAngajati.getAngajati()) {
        file << angajat->getNume() << " " << angajat->getPrenume() << ": Salariul: " << angajat->calculeazaSalariu() << " RON\n";
    }
    gestAngajati.top3AngajatiDupaSalariu();
}


int main() {
    gestiuneAngajati gestAngajati;
    gestiuneProduse gestProduse;
    gestiuneComenzi gestComenzi;

    adaugaAngajati(gestAngajati);
    adaugaProduse(gestProduse);
    adaugaComenzi(gestComenzi, gestProduse, gestAngajati);

    cout << "Angajati in magazin:\n";
    gestAngajati.afiseazaAngajati();
    cout << "\nProduse in stoc:\n";
    gestProduse.afiseazaProduse();
    cout << "\nComenzi:\n";
  //  gestComenzi.afiseazaComenzi();

    genereazaRapoarte(gestAngajati, gestComenzi);

    vector<Angajat> angajati = citesteAngajati("angajati.txt");
    vector<Produs> produse = citesteProduse("produse.txt");
    scrieRaportCSV("raport.csv", gestComenzi,gestProduse,gestAngajati);
    return 0;
}
