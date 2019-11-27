#include <iostream>
#include "Abonat_Skype_Romania.h"

Abonat_Skype_Romania::Abonat_Skype_Romania():Abonat_Skype() {
    this->mail = "";
}

Abonat_Skype_Romania::Abonat_Skype_Romania(int id, string nume, string nr_telefon, int id_skype, string mail)
:Abonat_Skype(id, nume, nr_telefon, id_skype) {
    this->mail = mail;
}

Abonat_Skype_Romania::~Abonat_Skype_Romania() {
    cout << "D Abonat Skype Romania";
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania& copie):Abonat_Skype(copie) {
    this->mail = copie.mail;
}

Abonat_Skype_Romania& Abonat_Skype_Romania::operator=(const Abonat_Skype_Romania& copie) {
    if(this == &copie)
        return *this;
    this->id = copie.id;
    this->nume = copie.nume;
    this->nr_telefon = copie.nr_telefon;
    this->id_skype = copie.id_skype;
    this->mail = copie.mail;
    return *this;
}

istream& operator>>(istream& in, Abonat_Skype_Romania& s) {
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
    cout << "Adresa de mail: ";
    in >> s.mail;
    return in;
}

ostream& operator<<(ostream& out, Abonat_Skype_Romania& s) {
    cout << "ID: ";
    out << s.id << endl;
    cout << "Nume: ";
    out << s.nume << endl;
    cout << "Numar de telefon: ";
    out << s.nr_telefon << endl;
    cout << "ID Skype: ";
    out << s.id_skype << endl;
    cout << "Adresa de mail: ";
    out << s.mail << endl;
    return out;
}

void Abonat_Skype_Romania::afisare()const {
    Abonat_Skype::afisare();
    cout << "Adresa de mail: ";
    cout << mail << endl;
}
