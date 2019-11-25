#ifndef ABONAT_SKYPE_H_INCLUDED
#define ABONAT_SKYPE_H_INCLUDED
#include <iostream>
#include "Abonat.h"
using namespace std;

class Abonat_Skype:public Abonat {
protected:
    int id_skype;
public:
    Abonat_Skype();
    Abonat_Skype(int, string, string, int);
    ~Abonat_Skype();
    Abonat_Skype(const Abonat_Skype&);
    Abonat_Skype& operator=(const Abonat_Skype&);
    friend istream& operator>>(istream& ,Abonat_Skype&);
    friend ostream& operator<<(ostream& ,Abonat_Skype&);
    void afisare()const;
};

#endif // ABONAT_SKYPE_H_INCLUDED
