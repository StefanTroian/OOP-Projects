#include <iostream>
#include "Abonat_Skype_Extern.h"

Abonat_Skype_Extern::Abonat_Skype_Extern() {
    this->tara = "";
}

Abonat_Skype_Extern::Abonat_Skype_Extern(int id, string nume, string nr_telefon, int id_skype, string tara)
:Abonat_Skype(id,nume,nr_telefon,id_skype) {
    this->tara = tara;
}

Abonat_Skype_Extern::~Abonat_Skype_Extern() {
    cout << "D Abonat Skype Extern";
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern &copie):Abonat_Skype(copie) {
    this->tara = copie.tara;
}

Abonat_Skype_Extern& Abonat_Skype_Extern::operator=(const Abonat_Skype_Extern& copie) {
    if(this == &copie)
        return *this;
    this->id = copie.id;
    this->nume = copie.nume;
    this->nr_telefon = copie.nr_telefon;
    this->id_skype = copie.id_skype;
    this->tara = copie.tara;
    return *this;
}

istream& operator>>(istream& in, Abonat_Skype_Extern& s) {
    cout << "ID: ";
    in >> s.id;
    try { if(s.id < 0)
            throw 1.0;
    } catch(double) {
        cout << "ID invalid\n";
        cout << "ID: " ;
        in >> s.id;
    }
    cout << "Nume: ";
    in >> s.nume;
    cout << "Numar de telefon: ";
    in >> s.nr_telefon;
    cout << "ID Skype: ";
    in >> s.id_skype;
    cout << "Tara: ";
    in >> s.tara;
    return in;
}

ostream& operator<<(ostream& out, Abonat_Skype_Extern& s) {
    cout << "ID: ";
    out << s.id << endl;
    cout << "Nume: ";
    out << s.nume << endl;
    cout << "Numar de telefon: ";
    out << s.nr_telefon << endl;
    cout << "ID Skype: ";
    out << s.id_skype << endl;
    cout << "Tara: ";
    out << s.tara << endl;
    return out;
}

void Abonat_Skype_Extern::afisare()const {
    Abonat_Skype::afisare();
    cout << "Tara: ";
    cout << tara << endl;
}
