
#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

class Animal //clasa comanda
{
private:
	string nume;
	int poz;
	int tip_derivat;
public:

	Animal(int tip_derivat)
	{
		this->tip_derivat = tip_derivat;
	}

	Animal(string nume, int poz, int tip_derivat) //constructor
	{
		this->nume = nume;
		this->poz= poz;
		this->tip_derivat = tip_derivat;
	}

	virtual void afisare_comanda() //metoda virtuala de afisare
	{
		cout << "---------------" << endl;
		cout << "Nume: " << nume << endl;
		cout << "Pozitie: " << poz << endl;
		
	}

	string getNume()
	{
		return nume;
	}

	int getNr_c()
	{
		return poz;
	}

	

	friend istream& operator >>(istream&, Animal*&);
	friend ostream& operator <<(ostream&, Animal*);
	friend void afisare(list<Animal*>);
	friend void cautare(list<Animal*>);
	friend bool afisare_tip(list<Animal*>,string);
	friend void scrie_fisier(list<Animal*>);
};

class Exotic : public Animal
{
private:
	string tara;
public:
	Exotic(string nume, int poz, int tip_derivat,string tara) : Animal(nume, poz, tip_derivat) //constructor
	{
		this->tara = tara;
	}

	void afisare_comanda()
	{
		Animal::afisare_comanda(); // apelam functia din clasa Comanda
		cout << "Tara: " << tara << endl;
	}

	
};

class Neexotic : public Animal
{
public:
	string mancare;
	Neexotic(string nume, int poz, int tip_derivat, string mancare) :Animal(nume, poz, tip_derivat){
		cin >> mancare; }

	void afisare_comanda()
	{
		Animal::afisare_comanda(); // apelam functia din clasa Comanda
		cout << mancare;
	}
};



istream& operator >> (istream& in, Animal*& a)// functia de supraincarcare a operatorului de citire
{
	string nume;
	int poz;
	int tip_derivat;
	string tara;
	string mancare;

	cout << endl << "Introduceti datele despre comanda: " << endl;

	if (a->tip_derivat == 0) // daca s-a ales adaugarea unui exotic
	{
		cout << "Introduceti nume exotic: ";
		in >> nume;
		cout << "Introduceti pozitie: ";
			in >> poz;		
		cout << "Introduceti tara: ";
		in >> tara;
		
		Exotic* r = new Exotic( nume,  poz, 0,  tara); //apelare constructor cu info citite
		a = r; //cast pentru clasa de baza

	}
	else if (a->tip_derivat == 1) //daca s-a ales adaugarea unei neexotice
	{
		cout << "Introduceti nume animal obisnuit: ";
		in >> nume;
		cout << "Introduceti pozitie: ";
		in >> poz;
		cout << "Introduceti mancare: ";
		in >> mancare; 
		Neexotic* l = new Neexotic( nume, poz, 1, mancare);
		a = l;//cast pentru clasa de baza
	}
	return in;
}

ostream& operator << (ostream& out, Animal* obj) 
{
	
	obj->afisare_comanda();
	return out;
}

void introducere(list<Animal*>& lista, int tip_derivat)
{
	Animal* pr = new Animal(tip_derivat);
	cin >> pr; // supraincarcarea citirii
	lista.push_back(pr);//se adauga nodul in spate
}

void afisare(list<Animal*> lista) //afisarea listei
{
	list <Animal*> ::iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		Animal* c = (*i);
		cout << c;
		char ch = _getch(); // afisare pas cu pas
	}
}

bool afisare_tip(list<Animal*> lista,string nt) //afisarea comenzilor dupa tip
{
	int tip;
	string nt;
	cout << "Pentru stergere dupa tara \n";
	
	cin >> nt;
	list<Animal*>::iterator i;

	for (i = lista.begin(); i != lista.end(); i++)
	{
			Animal* e = (*i);
		if (e->tara.compare(nt) == 0)
		{
			lista.erase(i);
			return true;
		}
	}

	return false;
}


void citire_fisier(list<Animal*>& lista)
{
	ifstream f("animale.txt");

	string nume;
	int poz;
	int tip_derivat;
	string tara;
	string mancare;

	Exotic* r = NULL;
	Neexotic* l = NULL;

	while (f >> nume >> poz >> tara >> tip_derivat)
	{
		//Comanda* c = new Comanda(nume, nr_c, plata, tip_derivat);

		if (tip_derivat == 0)
		{
			f >> tara;
			r = new Exotic (nume, poz, tip_derivat, tara);
			lista.push_back(r);
		}
		else
		{
			l = new Neexotic(nume, poz, tip_derivat,mancare);
			lista.push_back(l);
		}
	}
	f.close();
}

void main() //programul principal
{
	int opt;
	int t;
	string nut;
	// Lista eterogena cu comenzi pentru pachet si restaurant
	list<Animal*> c;
	do
	{
		system("CLS");
		cout << "1.Citirea animalelor din fisier.\n";
		cout << "2.Adaugare unui animal in spatele listei.\n";
		cout << "4.Stergere dupa tara.\n";
		cout << "5.Afisarea intregii liste.\n";
		cout << "6.Scrierea in fisier.\n";
		cout << "0.Iesire.\n";
		cout << "Dati optiunea dvs: ";
		cin >> opt;
		//apelare functii in functie de optiunea aleasa
		switch (opt)
		{
		case 1: citire_fisier(c);
			break;
		case 2:
			cout << "Exotic 1 sau neexotic 0 ";
			cin >> t;
			introducere(c, t);
			break;
		case 4:
			cin >> nut;
			afisare_tip(c,nut);
			break;
		case 5: afisare(c);
			break;
		case 6: scrie_fisier(c);
			break;
		case 0: break;
		default:cout << "Comanda gresita!";
		}
	} while (opt != 0);
}
