#ifndef ABONAT_H_INCLUDED
#define ABONAT_H_INCLUDED
#include <iostream>
#include "Persoana.h"
using namespace std;

class Abonat:public Persoana {
protected:
    string nr_telefon;
public:
    Abonat() ;
    Abonat(int, string, string);
    ~Abonat();
    Abonat(const Abonat&);
    Abonat& operator=(const Abonat&);
    friend istream& operator>>(istream& ,Abonat&);
    friend ostream& operator<<(ostream& ,Abonat&);
    void afisare()const;
};

#endif // ABONAT_H_INCLUDED
