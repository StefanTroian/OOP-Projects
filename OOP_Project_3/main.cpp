#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>
using namespace std;

class Animal {
protected:
    float greutate;
    pair<int, int> varsta;  //ani, luni
public:
    Animal();
    Animal(float, pair<int, int>);
    virtual ~Animal();
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    friend istream& operator>>(istream&, Animal&);
    virtual void citire(istream&);
    virtual void afisare()const;
};

Animal::Animal() {
    this->greutate = 0;
    this->varsta = make_pair(0,0);
}

Animal::Animal(float greutate, pair<int, int> varsta) {
    this->greutate = greutate;
    this->varsta = varsta;
}

Animal::~Animal() {
    //cout << "D Animal" << endl;
}

Animal::Animal(const Animal &copie) {
    this->greutate = copie.greutate;
    this->varsta = copie.varsta;
}

Animal& Animal::operator=(const Animal& copie) {
    if(this == &copie)
        return *this;
    this->greutate = copie.greutate;
    this->varsta = copie.varsta;
    return *this;
}

istream& operator>>(istream& in, Animal& a) {
    a.citire(in);
    return in;
}

void Animal::citire(istream& in) {
    cout << endl << "Greutate: ";
    in >> greutate;
    cout << "Varsta(ani luni): ";
    int an, luna;
    in >> an >> luna;
    varsta = make_pair(an, luna);
}

void Animal::afisare() const {
    cout << endl << "Greutate: " << greutate << " kg" << endl;
    cout << "Varsta: " << varsta.first << " ani " << varsta.second << " luni" << endl;
}

//--------------------------------------------------------------------------------------------

class Vertebrate:public Animal {
protected:
    const string tip = "Vertebrat";
    //int inaltime;   //cm
public:
    Vertebrate();
    Vertebrate(float, pair<int, int>);
    ~Vertebrate();
    Vertebrate(const Vertebrate&);
    Vertebrate& operator=(const Vertebrate&);
    friend istream& operator>>(istream&, Vertebrate&);
    void citire(istream&);
    void afisare()const;
};

Vertebrate::Vertebrate():Animal() {}

Vertebrate::Vertebrate(float greutate, pair<int, int> varsta):Animal(greutate,varsta) {}

Vertebrate::~Vertebrate() {
    //cout << "D Vertebrate" << endl;
}

Vertebrate::Vertebrate(const Vertebrate& copie):Animal(copie) {}

Vertebrate& Vertebrate::operator=(const Vertebrate& copie) {
    if(this == &copie)
        return *this;
    this->greutate = copie.greutate;
    this->varsta = copie.varsta;
    return *this;
}

istream& operator>>(istream& in, Vertebrate& a) {
    a.citire(in);
    return in;
}

void Vertebrate::citire(istream& in) {
    Animal::citire(in);
}

void Vertebrate::afisare()const {
    Animal::afisare();
    cout << "Tip: " << tip << endl;
}

//--------------------------------------------------------------------------------------------

class Nevertebrate:public Animal {
protected:
    const string tip = "Nevertebrat";
    //int inaltime;   //cm
public:
    Nevertebrate();
    Nevertebrate(float, pair<int, int>);
    ~Nevertebrate();
    Nevertebrate(const Nevertebrate&);
    Nevertebrate& operator=(const Nevertebrate&);
    friend istream& operator>>(istream&, Nevertebrate&);
    void citire(istream&);
    void afisare()const;
};

Nevertebrate::Nevertebrate():Animal() {}

Nevertebrate::Nevertebrate(float greutate, pair<int, int> varsta):Animal(greutate,varsta) {}

Nevertebrate::~Nevertebrate() {
    //cout << "D Nevertebrate" << endl;
}

Nevertebrate::Nevertebrate(const Nevertebrate& copie):Animal(copie) {}

Nevertebrate& Nevertebrate::operator=(const Nevertebrate& copie) {
    if(this == &copie)
        return *this;
    this->greutate = copie.greutate;
    this->varsta = copie.varsta;
    return *this;
}

istream& operator>>(istream& in, Nevertebrate& a) {
    a.citire(in);
    return in;
}

void Nevertebrate::citire(istream& in) {
    Animal::citire(in);
}

void Nevertebrate::afisare()const {
    Animal::afisare();
    cout << "Tip: " << tip << endl;
}

//--------------------------------------------------------------------------------------------

class Pasari:public Vertebrate {
protected:
    const string specie = "Pasare";
    bool zburatoare;
public:
    Pasari();
    Pasari(float, pair<int, int>, bool);
    ~Pasari();
    Pasari(const Pasari&);
    Pasari& operator=(const Pasari&);
    friend istream& operator>>(istream&, Pasari&);
    void citire(istream&);
    void afisare()const;
};

Pasari::Pasari():Vertebrate() {
    this->zburatoare = false;
}

Pasari::Pasari(float greutate, pair<int, int> varsta, bool zburatoare):Vertebrate(greutate,varsta) {
    this->zburatoare = zburatoare;
}

Pasari::~Pasari() {
    //cout << "D Pasari" << endl;
}

Pasari::Pasari(const Pasari& copie):Vertebrate(copie) {
    this->zburatoare = copie.zburatoare;
}

Pasari& Pasari::operator=(const Pasari& copie) {
    if(this == &copie)
        return *this;
    this->greutate = copie.greutate;
    this->varsta = copie.varsta;
    this->zburatoare = copie.zburatoare;
    return *this;
}

istream& operator>>(istream& in, Pasari& p) {
    p.citire(in);
    return in;
}

void Pasari::citire(istream& in) {
    Vertebrate::citire(in);
    cout << "1/0 - zburatoare/nezburatoare: ";
    in >> zburatoare;
}

void Pasari::afisare()const {
    if(zburatoare == 1)
        cout << specie << " zburatoare";
    else cout << specie << " nezburatoare";
    Vertebrate::afisare();
}

//--------------------------------------------------------------------------------------------

class Mamifere:public Vertebrate {
protected:
    const string specie = "Mamifer";
    bool blana;     //acoperite cu blana sau par
public:
    Mamifere();
    Mamifere(float, pair<int, int>, bool);
    ~Mamifere();
    Mamifere(const Mamifere&);
    Mamifere& operator=(const Mamifere&);
    friend istream& operator>>(istream&, Mamifere&);
    void citire(istream&);
    void afisare()const;
};

Mamifere::Mamifere():Vertebrate() {
    this->blana = true;
}

Mamifere::Mamifere(float greutate, pair<int ,int> varsta, bool blana):Vertebrate(greutate,varsta) {
    this->blana = blana;
}

Mamifere::~Mamifere() {
    //cout << "D Mamifere" << endl;
}

Mamifere::Mamifere(const Mamifere& copie):Vertebrate(copie) {
    this->blana = copie.blana;
}

Mamifere& Mamifere::operator=(const Mamifere& copie) {
    Vertebrate::operator=(copie);
    this->blana = copie.blana;
    return *this;
}

istream& operator>>(istream& in, Mamifere& m) {
    m.citire(in);
    return in;
}

void Mamifere::citire(istream& in) {
    Vertebrate::citire(in);
    cout << "1/0 - cu blana/ fara blana: ";
    in >> blana;
}

void Mamifere::afisare()const {
    if(blana == 1)
        cout << specie << " cu blana";
    else cout << specie << " fara blana";
    Vertebrate::afisare();
}

//--------------------------------------------------------------------------------------------

class Reptile:public Vertebrate {
protected:
    const string specie = "Reptila";
    bool taratoare;
public:
    Reptile();
    Reptile(float, pair<int, int>, bool);
    ~Reptile();
    Reptile(const Reptile&);
    Reptile& operator=(const Reptile&);
    friend istream& operator>>(istream&, Reptile&);
    void citire(istream&);
    void afisare()const;
};

Reptile::Reptile():Vertebrate() {
    this->taratoare = true;
}

Reptile::Reptile(float greutate, pair<int, int> varsta, bool taratoare):Vertebrate(greutate,varsta) {
    this->taratoare = taratoare;
}

Reptile::~Reptile() {
//    cout << "D Reptile" << endl;
}

Reptile::Reptile(const Reptile& copie):Vertebrate(copie) {
    this->taratoare = copie.taratoare;
}

Reptile& Reptile::operator=(const Reptile& copie) {
    Vertebrate::operator=(copie);
    this->taratoare = copie.taratoare;
    return *this;
}

istream& operator>>(istream& in, Reptile& r) {
    r.citire(in);
    return in;
}

void Reptile::citire(istream& in) {
    Vertebrate::citire(in);
    cout << "1/0 - taratoare/netaratoare: ";
    in >> taratoare;
}

void Reptile::afisare()const {
    if(taratoare == 1)
        cout << specie << " taratoare";
    else cout << specie << " netaratoare";
    Vertebrate::afisare();
}

//--------------------------------------------------------------------------------------------

class Scorpioni:public Nevertebrate {
protected:
    const string specie = "Scorpion";
    bool veninos;
public:
    Scorpioni();
    Scorpioni(float, pair<int, int>, bool);
    ~Scorpioni();
    Scorpioni(const Scorpioni&);
    Scorpioni& operator=(const Scorpioni&);
    friend istream& operator>>(istream&, Scorpioni&);
    void citire(istream&);
    void afisare()const;
};

Scorpioni::Scorpioni():Nevertebrate() {
    this->veninos = false;
}

Scorpioni::Scorpioni(float greutate, pair<int, int> varsta, bool veninos):Nevertebrate(greutate,varsta) {
    this->veninos = veninos;
}

Scorpioni::~Scorpioni() {
//    cout << "D Scorpion";
}

Scorpioni::Scorpioni(const Scorpioni& copie):Nevertebrate(copie) {
    this->veninos = copie.veninos;
}

Scorpioni& Scorpioni::operator=(const Scorpioni& copie) {
    Nevertebrate::operator=(copie);
    this->veninos = copie.veninos;
    return *this;
}

istream& operator>>(istream& in, Scorpioni& s) {
    s.citire(in);
    return in;
}

void Scorpioni::citire(istream& in) {
    Nevertebrate::citire(in);
    cout << "1/0 - veninos/neveninos: ";
    in >> veninos;
}

void Scorpioni::afisare()const {
    if(veninos == 1)
        cout << specie << " veninos";
    else cout << specie << " neveninos";
    Nevertebrate::afisare();
}

//--------------------------------------------------------------------------------------------

template <class T>
class Pesti;
template <class T>
istream& operator>>(istream&,Pesti<T>&);

template <class T = double>
class Pesti:public Vertebrate {
protected:
    const string specie = "Peste";
    T lungime;
    bool rapitor;
    static int nr_rapitor;
public:
    Pesti();
    Pesti(float, pair<int,int>, T, bool);
    ~Pesti();
    Pesti(const Pesti&);
    Pesti& operator=(const Pesti&);
    friend istream& operator>><>(istream&, Pesti<T>&);
    void citire(istream&);
    void afisare()const;
};

template <class T>
int Pesti<T>::nr_rapitor = 0;

template <class T>
Pesti<T>::Pesti():Vertebrate() {
    lungime = 0;
    rapitor = false;
}

template <class T>
Pesti<T>::Pesti(float greutate, pair<int,int> varsta, T lungime, bool rapitor):Vertebrate(greutate,varsta) {
    lungime = lungime;
    rapitor = rapitor;
    if(rapitor == 1 && lungime > 1)
        nr_rapitor++;
}

template <class T>
Pesti<T>::~Pesti() {
    //cout << "D Pesti " << endl;
}

template <class T>
Pesti<T>::Pesti(const Pesti& copie):Vertebrate(copie) {
    this->lungime = copie.lungime;
    this->rapitor = copie.rapitor;
    if(copie.rapitor == 1 && copie.lungime > 1)
        nr_rapitor++;
}

template <class T>
Pesti<T>& Pesti<T>::operator=(const Pesti& copie) {
    if(this == &copie)
        return *this;
    greutate = copie.greutate;
    varsta = copie.varsta;
    lungime = copie.lungime;
    rapitor = copie.rapitor;
    if(copie.rapitor == 1 && copie.lungime > 1)
        nr_rapitor++;
    return *this;
}

template <class T>
istream& operator>>(istream& in, Pesti<T>& p) {
    p.citire(in);
    return in;
}

template <class T>
void Pesti<T>::citire(istream& in) {
    Vertebrate::citire(in);
    cout << "Lungime: ";
    in >> lungime;
    cout << "1/0 - rapitor/nerapitor: ";
    in >> rapitor;
    if(rapitor == 1 && lungime > 1)
        nr_rapitor++;
}

template <class T>
void Pesti<T>::afisare()const {
    if(rapitor == 1)
        cout << specie << " rapitor";
    else cout << specie << " nerapitor";
    Vertebrate::afisare();
    cout << "Lungime: " << lungime << " m" << endl;
}

//--------------------------------------------------------------------------------------------

template <>
class Pesti<float>:public Vertebrate {
protected:
    const string specie = "Peste";
    float lungime;
    bool rapitor;
    static int nr_rapitor;
public:
    Pesti();
    Pesti(float, pair<int,int>, float, bool);
    ~Pesti();
    Pesti(const Pesti&);
    Pesti& operator=(const Pesti&);
    friend istream& operator>><>(istream&, Pesti<>&);
    void citire(istream&);
    void afisare()const;
};

int Pesti<float>::nr_rapitor = 0;

Pesti<float>::Pesti():Vertebrate() {
    lungime = 0;
    rapitor = false;
}

Pesti<float>::Pesti(float greutate, pair<int,int> varsta, float lungime, bool rapitor):Vertebrate(greutate,varsta) {
    lungime = lungime;
    rapitor = rapitor;
    if(rapitor == 1 && lungime > 1)
        nr_rapitor++;
}

Pesti<float>::~Pesti() {
    //cout << "D SPesti " << endl;
}

Pesti<float>::Pesti(const Pesti& copie):Vertebrate(copie) {
    this->lungime = copie.lungime;
    this->rapitor = copie.rapitor;
    if(copie.rapitor == 1 && copie.lungime > 1)
        nr_rapitor++;
}

Pesti<float>& Pesti<float>::operator=(const Pesti& copie) {
    if(this == &copie)
        return *this;
    greutate = copie.greutate;
    varsta = copie.varsta;
    lungime = copie.lungime;
    rapitor = copie.rapitor;
    if(copie.rapitor == 1 && copie.lungime > 1)
        nr_rapitor++;
    return *this;
}

istream& operator>>(istream& in, Pesti<float>& p) {
    p.citire(in);
    return in;
}

void Pesti<float>::citire(istream& in) {
    Vertebrate::citire(in);
    cout << "Lungime: ";
    in >> lungime;
    cout << "1/0 - rapitor/nerapitor: ";
    in >> rapitor;
    if(rapitor == 1 && lungime > 1)
        nr_rapitor++;
}

void Pesti<float>::afisare()const {
    if(rapitor == 1)
        cout << specie << " rapitor";
    else cout << specie << " nerapitor";
    Vertebrate::afisare();
    cout << "Lungime: " << lungime << " m" << endl;
    cout << "Numar pesti rapitori: " <<
    nr_rapitor/2 + Pesti::nr_rapitor << endl;
}

//--------------------------------------------------------------------------------------------

class Animale {
private:
    list<Animal*> a;
    int dim;
public:
    Animale();
    virtual ~Animale();
    friend istream& operator>>(istream& ,Animale&);
    friend ostream& operator<<(ostream& ,Animale&);
};

Animale::Animale() {
    this->dim = 0;
//    this->a = nullptr;
}

Animale::~Animale() {
    this->dim = 0;
//    this->a = nullptr;
//    a.remove();
}

istream& operator>>(istream& in, Animale& an) {
    cout << "Numar de animale: ";
    in >> an.dim;
    int op;
    for(int i = 0; i < an.dim; i++) {
        cout << "1 - Pasari" << endl;
        cout << "2 - Pesti (specializare)" << endl;
        cout << "3 - Pesti" << endl;
        cout << "4 - Mamifere" << endl;
        cout << "5 - Reptile" << endl;
        cout << "6 - Scorpioni" << endl;
        cout << "0 - Exit" << endl;
        cout << "Optiune: ";
        cin >> op;
        try {   if(op < 0 || op > 6)
                    throw 1.0;
        } catch(double) {
            cout << "Invalid option\n";
            cout << "Optiune: ";
            cin >> op;
        }
        switch(op) {
            case 1:
                {
                Pasari *x = new Pasari();
                cin >> (*x);
                an.a.push_back(x);
                break;
                }
            case 2:
                {
                Pesti<float> *x = new Pesti<float>();
                cin >> (*x);
                an.a.push_back(x);
                break;
                }
            case 3:
                {
                Pesti<> *x = new Pesti<>();
                cin >> (*x);
                an.a.push_back(x);
                break;
                }
            case 4:
                {
                Mamifere *x = new Mamifere();
                cin >> (*x);
                an.a.push_back(x);
                break;
                }
            case 5:
                {
                Reptile *x = new Reptile();
                cin >> (*x);
                an.a.push_back(x);
                break;
                }
            case 6:
                {
                Scorpioni *x = new Scorpioni();
                cin >> (*x);
                an.a.push_back(x);
                break;
                }
            default: break;
        }
        cout << endl;
    }
    return in;
}

ostream& operator<<(ostream& out, Animale& an) {
    cout << "\nANIMALE\n\n";
    for(auto e:an.a) {
        e->afisare();
        cout << endl;
    }
    return out;
}

//--------------------------------------------------------------------------------------------

class Atlas_zoologic {
    Animal **a;
    int num_animale;
    Atlas_zoologic() {}
    static Atlas_zoologic* instance;
public:
    static Atlas_zoologic* get_instance() {
        if(instance)
            return instance;
        instance = new Atlas_zoologic;
        return instance;
    }
    void add_animal(Animal* x) {
        if(typeid(*x) == typeid(Pasari))
            cin >> *dynamic_cast<Pasari*>(x);
        else if(typeid(*x) == typeid(Pesti<>))
            cin >> *dynamic_cast<Pesti<>*>(x);
        else if(typeid(*x) == typeid(Pesti<float>))
            cin >> *dynamic_cast<Pesti<float>*>(x);
        else if(typeid(*x) == typeid(Mamifere))
            cin >> *dynamic_cast<Mamifere*>(x);
        else if(typeid(*x) == typeid(Reptile))
            cin >> *dynamic_cast<Reptile*>(x);
        else if(typeid(*x) == typeid(Scorpioni))
            cin >> *dynamic_cast<Scorpioni*>(x);
        else cin >> *dynamic_cast<Animal*>(x);
        num_animale++;
        a[num_animale - 1] = x;
    }
    void citire();
    void afisare();
};

Atlas_zoologic* Atlas_zoologic::instance = nullptr;

void Atlas_zoologic::citire() {
    this->num_animale = 0;
    a = new Animal*[num_animale + 1];
    int op = 10;
    while(op)
    {
        cout << "1 - Pasari" << endl;
        cout << "2 - Pesti (specializare)" << endl;
        cout << "3 - Pesti" << endl;
        cout << "4 - Mamifere" << endl;
        cout << "5 - Reptile" << endl;
        cout << "6 - Scorpioni" << endl;
        cout << "0 - Exit" << endl;
        cout << "Optiune: ";
        cin >> op;
        try {   if(op < 0 || op > 6)
                    throw 1.0;
        } catch(double) {
            cout << "Invalid option\n";
            cout << "Optiune: ";
            cin >> op;
        }
        switch(op) {
            case 1: a[num_animale] = new Pasari();
                    cin >> *dynamic_cast<Pasari*>(a[num_animale]);
                    break;
            case 2: a[num_animale] = new Pesti<float>();
                    cin >> *dynamic_cast<Pesti<float>*>(a[num_animale]);
                    break;
            case 3: a[num_animale] = new Pesti<>();
                    cin >> *dynamic_cast<Pesti<>*>(a[num_animale]);
                    break;
            case 4: a[num_animale] = new Mamifere();
                    cin >> *dynamic_cast<Mamifere*>(a[num_animale]);
                    break;
            case 5: a[num_animale] = new Reptile();
                    cin >> *dynamic_cast<Reptile*>(a[num_animale]);
                    break;
            case 6: a[num_animale] = new Scorpioni();
                    cin >> *dynamic_cast<Scorpioni*>(a[num_animale]);
                    break;
            default: break;
        }
        this->num_animale++;
        cout << endl;
    }
    this->num_animale--;
}

void Atlas_zoologic::afisare() {
    cout << endl << "ATLAS" << endl;
    cout << "Total animale: " << num_animale << endl << endl;
    for(int i = 0; i < this->num_animale ; i++) {
        a[i]->afisare();
        cout << endl;
    }
}

int main()
{   ///citire singleton
    Atlas_zoologic* an = Atlas_zoologic::get_instance();
    an->citire();            ///citirea si afisarea agendei
    an->afisare();

    ///adaugarea unui element
    Mamifere p;
    an->add_animal(&p);
    an->afisare();

    ///clasa pt citirea animalelor
    Animale ani;
    cin >> ani;
    cout << ani;
    return 0;
}
