#include <iostream>
#include "Persoana.h"

Persoana::Persoana() {
    this->id = 0;
    this->nume = "";
}

Persoana::Persoana(int id, string nume) {
    this->id = id;
    this->nume = nume;
}

Persoana::~Persoana() {
    cout << "D persoana";
}

Persoana::Persoana(const Persoana &copie) {
    this->id = copie.id;
    this->nume = copie.nume;
}

Persoana& Persoana::operator=(const Persoana& copie) {
    if(this == &copie)
        return *this;
    this->id = copie.id;
    this->nume = copie.nume;
    return *this;
}

istream& operator>>(istream& in, Persoana& p) {
    cout << "ID: ";
    in >> p.id;
    cout << "Nume: ";
    in >> p.nume;
    return in;
}

ostream& operator<<(ostream& out, Persoana& p) {
    cout << "ID: ";
    out << p.id << endl;
    cout << "Nume: ";
    out << p.nume;
    out << endl;
    return out;
}

string Persoana::get_nume() {
    return nume;
}

void Persoana::afisare()const {
    cout << "ID: ";
    cout << id << endl;
    cout << "Nume: ";
    cout << nume << endl;
}
