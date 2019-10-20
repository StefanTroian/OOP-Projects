#include <iostream>
#include "Multime.h"

int main()
{
    ///supraincarcarea operatorilor << , >>
    Multime m1;
    cout << "MULTIME 1\n";
    cin >> m1;
    cout << m1;

    Multime m2;
    cout << "\nMULTIME 2\n";
    cin >> m2;
    cout << m2;

    ///intersectie
    Multime g;
    g = m1 * m2;
    g.afisare();

    ///diferenta
    Multime m5;
    m5 = (m1 - m2);
    m5.afisare();
    //cout << m5;

    ///reuniune
    Multime m3;
    m3 = (m1 + m2);
    m3.afisare();
    cout << endl;

    ///citirea a n multimi
    int n;
    cout << "Numar de multimi: ";
    cin >> n;
    Multime *m;
    m = Multime::informatii_obiecte(n);
    for(int i = 0;i < n; i++)
        cout << m[i];

    return 0;
}
