#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include <iostream>
#include "Abonat.h"
using namespace std;

class Agenda {
    Abonat **a;
    int dim;
public:
    Agenda();
    Agenda(int);
    ~Agenda();
    friend istream& operator>>(istream& ,Agenda&);
    friend ostream& operator<<(ostream& ,Agenda&);
    void citire();
    void afisare_agenda();
    Abonat& operator[](string);
};

#endif // AGENDA_H_INCLUDED
