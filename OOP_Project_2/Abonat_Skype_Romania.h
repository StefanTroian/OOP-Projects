#ifndef ABONAT_SKYPE_ROMANIA_H_INCLUDED
#define ABONAT_SKYPE_ROMANIA_H_INCLUDED
#include <iostream>
#include "Abonat_Skype.h"
using namespace std;

class Abonat_Skype_Romania:public Abonat_Skype {
protected:
    string mail;
public:
    Abonat_Skype_Romania();
    Abonat_Skype_Romania(int, string, string, int, string);
    ~Abonat_Skype_Romania();
    Abonat_Skype_Romania(const Abonat_Skype_Romania&);
    Abonat_Skype_Romania& operator=(const Abonat_Skype_Romania&);
    friend istream& operator>>(istream&, Abonat_Skype_Romania&);
    friend ostream& operator<<(ostream&, Abonat_Skype_Romania&);
    void afisare()const;
};

#endif // ABONAT_SKYPE_ROMANIA_H_INCLUDED
