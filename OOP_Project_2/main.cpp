#include <iostream>
#include "Agenda.h"

using namespace std;

int main()
{
    int n;
    cout << "Numar abonati: ";
    cin >> n;
    Agenda ag(n);
    ag.citire();            ///citirea si afisarea agendei
    ag.afisare_agenda();

    string nume_cautat;
    cout << endl << "Numele abonatului cautat: ";
    cin >> nume_cautat;
    cout << ag[nume_cautat];        ///returneaza abonatul din agenda cu numele cautat
                                    /// sau un abonat cu id 0 in caz contrar

    /* varianta 2 citire agenda
    Agenda ag;
    cin >> ag;
    cout << ag;
    */

    return 0;
}
