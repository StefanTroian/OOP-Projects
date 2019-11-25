#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED
#include <iostream>
using namespace std;

class Persoana {
protected:
    int id;
    string nume;
public:
    Persoana();
    Persoana(int ,string);
    virtual ~Persoana();
    Persoana(const Persoana&);
    Persoana& operator=(const Persoana&);
    friend istream& operator>>(istream& ,Persoana&);
    friend ostream& operator<<(ostream& ,Persoana&);
    virtual void afisare()const = 0;        ///functie virtuala pura
    string get_nume();      ///functie folosita ulterior pentru a afisa abonat(string)
};

#endif // PERSOANA_H_INCLUDED
