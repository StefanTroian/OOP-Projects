#include <iostream>
#include "Abonat_Skype.h"

Abonat_Skype::Abonat_Skype():Abonat() {
    this->id_skype = 0;
}

Abonat_Skype::Abonat_Skype(int id, string nume, string nr_telefon, int id_skype):Abonat(id,nume,nr_telefon) {
    this->id_skype = id_skype;
}

Abonat_Skype::~Abonat_Skype() {
    cout << "D abonat skype";
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype &copie):Abonat(copie) {
    this->id_skype = copie.id_skype;
}

Abonat_Skype& Abonat_Skype::operator=(const Abonat_Skype &copie) {
    if(this == &copie)
        return *this;
    this->id = copie.id;
    this->nume = copie.nume;
    this->nr_telefon = copie.nr_telefon;
    this->id_skype = copie.id_skype;
    return *this;
}

istream& operator>>(istream &in, Abonat_Skype &a) {
    cout << "ID: ";
    in >> a.id;
    try { if(s.id < 0)
            throw 1.0;
    } catch(double) {
        cout << "ID invalid\n";
        cout << "ID: " ;
        in >> s.id;
    }
    cout << "Nume: ";
    in >> a.nume;
    cout << "Numar de telefon: ";
    in >> a.nr_telefon;
    cout << "ID Skype: ";
    in >> a.id_skype;
    return in;
}

ostream& operator<<(ostream &out, Abonat_Skype &a) {
    cout << "ID: ";
    out << a.id << endl;
    cout << "Nume: ";
    out << a.nume << endl;
    cout << "Numar de telefon: ";
    out << a.nr_telefon << endl;
    cout << "ID Skype: ";
    out << a.id_skype;
    out << endl;
    return out;
}

void Abonat_Skype::afisare()const {
    Abonat::afisare();
    cout << "ID Skype: ";
    cout << id_skype << endl;
}
