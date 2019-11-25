#ifndef ABONAT_SKYPE_EXTERN_H_INCLUDED
#define ABONAT_SKYPE_EXTERN_H_INCLUDED
#include <iostream>
#include "Abonat_Skype.h"
using namespace std;

class Abonat_Skype_Extern:public Abonat_Skype {
protected:
    string tara;
public:
    Abonat_Skype_Extern();
    Abonat_Skype_Extern(int, string, string, int, string);
    ~Abonat_Skype_Extern();
    Abonat_Skype_Extern(const Abonat_Skype_Extern&);
    Abonat_Skype_Extern& operator=(const Abonat_Skype_Extern&);
    friend istream& operator>>(istream&, Abonat_Skype_Extern&);
    friend ostream& operator<<(ostream&, Abonat_Skype_Extern&);
    void afisare()const;
};

#endif // ABONAT_SKYPE_EXTERN_H_INCLUDED
