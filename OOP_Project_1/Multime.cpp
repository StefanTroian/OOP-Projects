#include <iostream>
#include "Multime.h"

Multime::Multime() {
    this->nr_elem = 0;
    this->vec = new int[this->nr_elem];
}

Multime::Multime(int nr_elem, int* vec) {
    this->nr_elem = nr_elem;
    this->vec = new int[this->nr_elem];
    for(int i = 0; i < nr_elem; i++) {
        this->vec[i] = vec[i];
    }
    //eliminearea duplicatelor prin apelarea functiei
    vector_multime();
}

Multime::~Multime() {
//    cout << "Destructor\n";
    this->nr_elem = 0;
    delete[] this->vec;
}

///compare folosit ulterior la qsort in functia vector_multime
int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

Multime::Multime(const Multime &copie) {
    this->nr_elem = copie.nr_elem;
    this->vec = new int[this->nr_elem];
    for(int i = 0; i < nr_elem; i++) {
        this->vec[i] = copie.vec[i];
    }
}

Multime Multime::operator+(Multime& m) {
    Multime rez;
    rez.nr_elem = this->nr_elem + m.nr_elem;
    rez.vec = new int[rez.nr_elem + 1];

    for( int i = 0; i < this->nr_elem; i++) {
        rez.vec[i] = this->vec[i];
    }
    for( int i = this->nr_elem; i < rez.nr_elem; i++) {
        rez.vec[i] = m.vec[i-this->nr_elem];
    }
    cout << "Reuniune: ";
    if(rez.nr_elem == 0)
        cout << "Multimea vida";

    rez.vector_multime();
    return rez;
}

Multime Multime::operator-(Multime& m) {
    Multime rez;
    rez.nr_elem = 0;

    for(int i = 0; i < this->nr_elem; i++) {
        int ok = 0;
        for(int j = 0; j < m.nr_elem; j++)
            if(this->vec[i] == m.vec[j])
                ok = 1;
        if(ok == 0) {
            rez.vec[rez.nr_elem] = this->vec[i];
            rez.nr_elem++;
        }
    }
    cout << "Diferenta: ";
    if(rez.nr_elem == 0)
        cout << "Multimea vida";

    return rez;
}

Multime Multime::operator*(Multime& m) {
    Multime rez;
    rez.nr_elem = 0;
    rez.vec = new int[rez.nr_elem];
    for(int i = 0; i < this->nr_elem; i++) {
        for(int j = 0; j < m.nr_elem; j++)
            if(this->vec[i] == m.vec[j]) {
                rez.vec[rez.nr_elem] = m.vec[i];
                rez.nr_elem++;
        }
    }
    cout << "Intersectie: ";
    if(rez.nr_elem == 0)
        cout << "Multimea vida";

    return rez;
}

Multime& Multime::operator=(const Multime& copie) {
    if(this == &copie)
        return *this;
    if(this->vec) {
        delete[] this->vec;
    }
    this->nr_elem = copie.nr_elem;
    this->vec = new int[this->nr_elem + 1];
    for(int i = 0; i < copie.nr_elem; i++)
        this->vec[i] = copie.vec[i];
    return *this;
}

istream& operator>>(istream& in, Multime& m) {
    cout << "Numar elemente: ";
    in >> m.nr_elem;
    m.vec = new int[m.nr_elem];
    cout << "Elemente vector: ";
    for(int i = 0; i < m.nr_elem; i++) {
        in >> m.vec[i];
    }
    m.vector_multime();
    return in;
}

ostream& operator<<(ostream& out, Multime& m) {
//    m.vector_multime();
    out << "Multime cu " << m.nr_elem << " elemente: ";
    for(int i = 0; i < m.nr_elem; i++) {
        out << m.vec[i] << " ";
    }
    out << endl;
    return out;
}

void Multime::vector_multime() {
    ///sortam vectorul pentru a avea aceleasi elemente pe pozitii consecutive
    ///fiind mai usor la sters
    qsort(this->vec,this->nr_elem,sizeof(int),compare);
    for(int  i = 0; i < this->nr_elem-1; i++) {
        if(this->vec[i] == this->vec[i+1]) {
            for(int j = i; j < this->nr_elem-1; j++)
                this->vec[j] = this->vec[j+1];
            this->nr_elem--;
            i--;
        }
    }
}

void Multime::afisare() {
//    vector_multime();
    for(int i = 0; i < nr_elem; i++)
        cout << vec[i] << " ";
    cout << endl;
}

Multime* Multime::informatii_obiecte(int n) {
    //cin >> n;
    Multime *M = new Multime[n];
    for(int i = 0; i < n; i++) {
        cin >> M[i];
    }
    return M;
}
