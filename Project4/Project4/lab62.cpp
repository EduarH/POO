#include<iostream>
#include<conio.h>
#include<string> 
using namespace std;

class Lista;  //prototipul clasei Lista

class Produse_magazin  //clasa de baza Produse_magazin
{
private:
	int tip_derivat;  //Ex. 1-Scanere, 2-Imprimante
	string producator; //Ex. Samsung, Hp, Lexmark, etc.
	int pret;   //Ex. 232345, 12423, 23563, etc.
	string rezolutie;  //Ex. 1200x700, 2000x1000, etc.
	
	Produse_magazin *urm;  //adresa urm element din lista
public:
	Produse_magazin(int t, string prod, int pre, string rez)  //constructor clasa de baza
	{

		tip_derivat = t;
		producator = prod;
		pret = pre;
		rezolutie = rez;
	
		urm = NULL; //adresa noului nod este initial NULL
	}

	virtual void afisare() //functia de afisare elemente clasa de baza
	{
		cout << "-----------------------------------------\n";
		cout << "Producator: " << producator << endl;
		cout << "Pret: " << pret << endl;
		cout << "Rezolutie: " << rezolutie << endl;
	
	}
	friend class Lista; //declararea clasei Lista friend la clasa Produse_magazin, pentru a se avea acces la campurile acesteia
};

class rama :public Produse_magazin //prima clasa derivata
{
private:
	string diagonala; 
	string format; 
public:
	rama(int t, string prod, int pre, string rez, string dia,string form) :Produse_magazin(t, prod,pre, rez) //constructor clasa derivata
	{
		diagonala = dia;
		format = form;
	}

	void afisare() //afisare elemente din clasa Scanere
	{
		Produse_magazin::afisare(); //apelare afisare elemente din clasa de baza
		cout << "Diagonala: " << diagonala << endl;
		cout << "Format: " <<format << endl;
	}
	friend class Lista;
};

class aparat :public Produse_magazin // a doua clasa derivata
{
private:
	string tipaparat; //Ex. A3, A3/A4/A5, A4, etc.
	string tipsenzor;    //Ex. Color, Monocrom
public:
	aparat(int t, string prod, int pre, string rez, string tipa, string tips) :Produse_magazin(t, prod, pre, rez) //constructor
	{
		tipaparat = tipa;
		tipsenzor = tips;
	}

	void afisare() //functie afisare
	{
		Produse_magazin::afisare();
		cout << "Tip aparat: " << tipaparat << endl;
		cout << "Tip senzor: " << tipsenzor << endl;
	}
	friend class Lista;
};


class Lista //clasa Lista
{
public:
	Produse_magazin *head; //capul listei
	void adaugare(Produse_magazin *prod); //adaugare in lista
	void afisare_lista0();
	void afisare_lista1(); //afisarea listei
	void afisare_lista();

};

//adaugare in lista ordonata
void Lista::adaugare(Produse_magazin *a)
{
	Produse_magazin *p; //var p este declarata de tip Produse_magazin

	p = head; //se initializeaza cu capul listei
	if (p) //daca lista nu este vida
	{
		if (a->producator.compare(p->producator) < 0) //daca nodul care se adauga este mai mic decat primul nod din lista 
		{
			a->urm = head; //noul nod se leaga de primul nod
			head = a; //capul listei devine noul nod
		}
		else
		{
			while (p->urm && (p->urm->producator.compare(a->producator) < 0))  //se parcurge lista pana cand exista elemente si noul nod nu este mai mare decat nodul curent
				p = p->urm;
			a->urm = p->urm; //se fac legaturile intre noul nod si cele din lista
			p->urm = a;
		}
	}
	else
		head = a; //daca lista este vida, capul este nodul adaugat
}

void Lista::afisare_lista() //afisarea listei
{
	Produse_magazin *a;

	a = head; //se initializeaza cu capul listei

	if (!a) //daca lista este vida
		cout << "Lista este vida!";
	else
		while (a) //cat timp sunt noduri in lista
		{
			a->afisare(); //se apeleaza afisarea corespunzatoare nodului curent
			a = a->urm; //se trece la urm nod in lista
			_getch();
		}
}


void Lista::afisare_lista1() //afisarea listei
{
	Produse_magazin *prodMag;
	aparat *Sc;

	prodMag = head;
	if (!prodMag)
		cout << "Lista este vida!";
	else
		while (prodMag) //daca lista nu este vida
		{
			if (prodMag->tip_derivat == 0) //daca nodul este rama
			{
				Sc = (aparat *)prodMag; //se face cast la Scanere pentru a avea acces la informatiile din clasa derivata

				prodMag->afisare();
			}
			prodMag = prodMag->urm; //se inainteaza in lista
		}
}

void Lista::afisare_lista0() //afisarea listei
{
	Produse_magazin *prodMag;
	rama *Sc;

	prodMag = head;
	if (!prodMag)
		cout << "Lista este vida!";
	else
		while (prodMag) //daca lista nu este vida
		{
			if (prodMag->tip_derivat == 0) //daca nodul este rama
			{
				Sc = (rama *)prodMag; //se face cast la Scanere pentru a avea acces la informatiile din clasa derivata

				prodMag->afisare();
			}
			prodMag = prodMag->urm; //se inainteaza in lista
		}
}
void introducere(Lista &l, int x) //introducere info in noduri
{
	int Tip_derivat;  //Ex. 1-Scanere, 2-Imprimante
	string Producator; //Ex. Samsung, Hp, Lexmark, etc.
	int Pret;   //Ex. 232345, 12423, 23563, etc.
	string Rezolutie;  //Ex. 1200x700, 2000x1000, etc.
	string  Diagonala; //Ex. Canon imageFormula, HP Scanjet Enterprise 
	string  Format; //Ex. A3, A3/A4/A5, A4, etc.
	string  Tipaparat;    //Ex. Color, Monocrom
	string Tipsenzor;
	Produse_magazin *prodMag;

	cout << "Introduceti producatorul: ";
	cin >> Producator;
	cout << "Introduceti pret: ";
	cin >> Pret;
	cout << "Introduceti rezolutia: ";
	cin >> Rezolutie;
	

	if (x == 0) // daca s-a ales adaugarea unui nou rama
	{
		rama *Sc;
		cout << "Introduceti diagonala: ";
		cin >> Diagonala;
		cout << "Introduceti format: ";
		cin >> Format;

		Sc = new rama(1, Producator, Pret, Rezolutie, Diagonala, Format); //apelare constructor cu info citite
		prodMag = Sc; //cast pentru clasa de baza
		l.adaugare(prodMag); //se adauga nodul
	}
	else if (x == 1) //daca s-a ales adaugarea unui aparat
	{
		aparat *Imprim;

		cout << "Introduceti tip aparat: ";
		cin >> Tipaparat;
		cout << "Introduceti tipul senzor: ";
		cin >> Tipsenzor;
		Imprim = new aparat(2, Producator, Pret, Rezolutie,Tipaparat, Tipsenzor);//apelare constructor cu info citite
		prodMag = Imprim;//cast pentru clasa de baza
		l.adaugare(prodMag);//se adauga nodul
	}
}



void main() //programul principal
{
	int opt,nr;
	Lista l;
	l.head = NULL;
	string soft;
	string produc;
	do
	{
		system("CLS");
		//meniu
		cout << "1.Adaugare rama in lista, ordonat dupa producator.\n";
		cout << "2.Adaugare aparat in lista, ordonat dupa producator.\n";
		cout << "3.Afisare rame din magazin.\n";
		cout << "4.Afisare aparate din magazin. \n";

		cout << "0.Iesire.\n";
		cout << "Dati optiunea dvs: ";
		cin >> opt;
		//apelare functii in functie de optiunea aleasa
		switch (opt)
		{
		case 1: introducere(l, 0);
			break;
		case 2: introducere(l, 1);
			break;
		case 3:
			cout << "Afisare rame \n";
			l.afisare_lista0();
			_getch();
			break;
		case 4:
			cout << "Afisare aparate \n ";
			
			l.afisare_lista1();
			_getch();
			break;
		case 0: break;
		default:cout << "Comanda gresita!";
		}
	} while (opt != 0);
}

