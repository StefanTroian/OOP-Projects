#include <iostream>
#include "Abonat.h"

Abonat::Abonat():Persoana() {
    this->nr_telefon = "";
}

Abonat::Abonat(int id, string nume, string nr_telefon):Persoana(id,nume) {
    this->nr_telefon = nr_telefon;
}

Abonat::~Abonat() {
    cout << "D abonat";
}

Abonat::Abonat(const Abonat &copie):Persoana(copie) {
    this->nr_telefon = copie.nr_telefon;
}

Abonat& Abonat::operator=(const Abonat &copie) {
    if(this == &copie)
        return *this;
    this->id = copie.id;
    this->nume = copie.nume;
    this->nr_telefon = copie.nr_telefon;
    return *this;
}

istream& operator>>(istream &in, Abonat &a) {
    cout << "ID: ";
    in >> a.id;
    try { if(a.id < 0)
            throw 1.0;
    } catch(double) {
        cout << "ID invalid\n";
        cout << "ID: " ;
        in >> a.id;
    }
    cout << "Nume: ";
    in >> a.nume;
    cout << "Numar de telefon: ";
    in >> a.nr_telefon;
    return in;
}

ostream& operator<<(ostream &out, Abonat &a) {
    cout << "ID: ";
    out << a.id << endl;
    cout << "Nume: ";
    out << a.nume << endl;
    cout << "Numar de telefon: ";
    out << a.nr_telefon;
    out << endl;
    return out;
}

void Abonat::afisare()const {
    Persoana::afisare();
    cout << "Numar de telefon: ";
    cout << nr_telefon << endl;
}
