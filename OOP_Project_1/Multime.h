#ifndef MULTIME_H_INCLUDED
#define MULTIME_H_INCLUDED
#include <iostream>
using namespace std;

class Multime {
private:
    int nr_elem;
    int *vec;

public:
    Multime();
    Multime(int , int* );                           ///Constructor
    ~Multime();                                     ///Destructor
    Multime(const Multime &);                       ///Constructor de copiere
    Multime operator+(Multime&);                    ///Reuniune multimi
    Multime operator-(Multime);                     ///Diferenta multimi
    Multime& operator=(const Multime&);             ///Supraincarcare operator egal
    Multime(const Multime &, const Multime &);      ///Intersectie multimi
    friend istream& operator>>(istream&,Multime&);  ///Citire multime
    friend ostream& operator<<(ostream&,Multime&);  ///Afisare multime
    void vector_multime();                          ///Transformare vector in multime
    void afisare();                                 ///Functie separata de afisare
    static Multime* informatii_obiecte(int);        ///Citirea a n multimi
};

#endif // MULTIME_H_INCLUDED
