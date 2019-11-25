#include <iostream>
#include "Agenda.h"
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Romania.h"
#include "Abonat_Skype_Extern.h"

Agenda::Agenda() {
    this->dim = 0;
    this->a = new Abonat*[dim];
}

Agenda::Agenda(int dim) {
    this->dim = dim;
    this->a = new Abonat*[this->dim];
}

Agenda::~Agenda() {
    //cout << "D Agenda";
    //for(int i = 0; i < this->dim; i++)
      //  delete[] a[i];
    dim = 0;
    delete[] a;
}

istream& operator>>(istream& in, Agenda& ag) {
    cout << "Numar de abonati: ";
    in >> ag.dim;
    ag.a = new Abonat*[ag.dim];
    int op;
    for(int i = 0; i < ag.dim; i++) {
        cout << "1 - Abonat_Skype_Romania" << endl;
        cout << "2 - Abonat_Skype_Extern" << endl;
        cout << "3 - Abonat_Skype" << endl;
        cout << "4 - Abonat" << endl;
        cout << "Optiune: ";
        cin >> op;
        switch(op) {
            case 1: ag.a[i] = new Abonat_Skype_Romania();
                    in >> *dynamic_cast<Abonat_Skype_Romania*>(ag.a[i]);
                    break;
            case 2: ag.a[i] = new Abonat_Skype_Extern();
                    in >> *dynamic_cast<Abonat_Skype_Extern*>(ag.a[i]);
                    break;
            case 3: ag.a[i] = new Abonat_Skype();
                    in >> *dynamic_cast<Abonat_Skype*>(ag.a[i]);
                    break;
            case 4: ag.a[i] = new Abonat();
                    in >> *dynamic_cast<Abonat*>(ag.a[i]);
                    break;
            default: break;
        }
        cout << endl;
    }
    return in;
}

ostream& operator<<(ostream& out, Agenda& ag) {
    cout << "\nAfisare: \n";
    for(int i = 0; i < ag.dim; i++) {
        out << *ag.a[i];
        cout << endl;
    }
    return out;
}

void Agenda::citire() {
    int op;
    for(int i = 0; i < this->dim; i++) {
        cout << "1 - Abonat_Skype_Romania" << endl;
        cout << "2 - Abonat_Skype_Extern" << endl;
        cout << "3 - Abonat_Skype" << endl;
        cout << "4 - Abonat" << endl;
        cout << "Optiune: ";
        cin >> op;
        switch(op) {
            case 1: a[i] = new Abonat_Skype_Romania();
                    cin >> *dynamic_cast<Abonat_Skype_Romania*>(a[i]);
                    break;
            case 2: a[i] = new Abonat_Skype_Extern();
                    cin >> *dynamic_cast<Abonat_Skype_Extern*>(a[i]);
                    break;
            case 3: a[i] = new Abonat_Skype();
                    cin >> *dynamic_cast<Abonat_Skype*>(a[i]);
                    break;
            case 4: a[i] = new Abonat();
                    cin >> *dynamic_cast<Abonat*>(a[i]);
                    break;
            default: break;
        }
        cout << endl;
    }
}

void Agenda::afisare_agenda() {
    cout << "\nAfisare: \n";
    for(int i = 0; i < this->dim; i++) {
        a[i]->afisare();
        cout << endl;
    }
}

Abonat& Agenda::operator[](string nume) {
    Abonat* rez = new Abonat();
    for(int i = 0; i < this->dim; i++)
        if(nume == a[i]->get_nume())
            return *a[i];
    return *rez;
}
