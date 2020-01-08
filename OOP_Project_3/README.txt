- implementare C++

S-au implementat urmatoarele clase:
		clasa Animal
clasa Vertebrate	clasa Nevertebrate
 clasa Pasari		 clasa Scorpioni
 clasa Mamifere
 clasa Reptile
 clasa Pesti (template + specializare)

Clasele contin:
-constructori (+ de copiere) 
-destructori
-supraincarcare op =, op>> ca si friend
-functii viruale rescrise in clasele derivate
-concepte de mostenire
-tratare de exceptii
-concepte de RTTI
-variabile si functii statice si const

In plus sunt 2 clase care citesc n obiecte de tip animal:
clasa Animale (care utilizeaza STL-ul prin list<Animal*>)
clasa Atlas_zoologic (singleton)
	-care utilizeaza un vector de animale alocat dinamic
	-functie de adaugare a unui animal