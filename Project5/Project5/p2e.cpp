#include<iostream>
#include<string.h>
#include<conio.h>
#include<string>

using namespace std;

class Lista;  //prototipul clasei Lista

class Produse_magazin  //clasa de baza Produse_magazin
{
private:
	int tip_derivat;  //Ex. 1-Scanere, 2-Imprimante
	string producator; //Ex. Samsung, Hp, Lexmark, etc.

	string denumire;  //Ex. 1200x700, 2000x1000, etc.

	Produse_magazin *urm;  //adresa urm element din lista
public:
	Produse_magazin(int t, string prod, string den)  //constructor clasa de baza
	{

		tip_derivat = t;
		producator = prod;
		denumire = den;

		urm = NULL; //adresa noului nod este initial NULL
	}

	virtual void afisare() //functia de afisare elemente clasa de baza
	{
		cout << "-----------------------------------------\n";
		cout << "Producator: " << producator << endl;
		cout << "Denumire: " << denumire << endl;

	}
	friend class Lista; //declararea clasei Lista friend la clasa Produse_magazin, pentru a se avea acces la campurile acesteia
};

class creioane :public Produse_magazin //prima clasa derivata
{
private:
	string mina;

public:
	creioane(int t, string prod, string den, string min) :Produse_magazin(t, prod, den)
	{
		mina = min;

	}

	void afisare()
	{
		Produse_magazin::afisare(); //apelare afisare elemente din clasa de baza
		cout << "Tip mina " << mina << endl;

	}
	friend class Lista;
};
class pix :public Produse_magazin // a doua clasa derivata
{
private:
	string culoare;

public:
	pix(int t, string prod, string den, string cul) :Produse_magazin(t, prod, den) //constructor
	{

		culoare = cul;
	}

	void afisare() //functie afisare
	{
		Produse_magazin::afisare();
		cout << "Culoare: " << culoare << endl;
	}
	friend class Lista;
};


class Lista //clasa Lista
{
public:
	Produse_magazin *head; //capul listei
	void adaugare(Produse_magazin *prod); //adaugare in lista
	void afisare_lista(); //afisarea listei
	void afisare_lista1();
	void afisare_listac(string soft);
	void afisare_listad(string so);
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
			if (a->tip_derivat == 1) {
				a->afisare();
			} //se apeleaza afisarea corespunzatoare nodului curent
			a = a->urm; //se trece la urm nod in lista
			_getch();
		}
}

void Lista::afisare_lista1() //afisarea listei
{
	Produse_magazin *a;

	a = head; //se initializeaza cu capul listei

	if (!a) //daca lista este vida
		cout << "Lista este vida!";
	else
		while (a) //cat timp sunt noduri in lista
		{
			if (a->tip_derivat == 2) {
				a->afisare();
			} //se apeleaza afisarea corespunzatoare nodului curent
			a = a->urm; //se trece la urm nod in lista
			_getch();
		}
}

void Lista::afisare_listac(string soft) //afisarea listei
{
	Produse_magazin *produMag;
	pix *Sc;

	produMag = head;
	if (!produMag)
		cout << "Lista este vida!";
	else
		while (produMag) //daca lista nu este vida
		{

			{
				Sc = (pix *)produMag;
				if (Sc->culoare.compare(soft) == 0)
				{
					produMag->afisare();
				}
			}
			produMag = produMag->urm; //se inainteaza in lista
		}
}


void Lista::afisare_listad(string sof) //afisarea listei
{
	Produse_magazin *a;

	a = head; //se initializeaza cu capul listei

	if (!a) //daca lista este vida
		cout << "Lista este vida!";
	else
		while (a) //cat timp sunt noduri in lista
		{
			if (a->denumire.compare(sof)) {
				a->afisare();
			} //se apeleaza afisarea corespunzatoare nodului curent
			a = a->urm; //se trece la urm nod in lista
			_getch();
		}
}


class Supraincarcare // clasa utilizata pentru supraincarcarea operatorilor
{
public:

	string producator; //Ex. Samsung, Hp, Lexmark, etc.

	string denumire;

public:
	friend ostream & operator <<(ostream &out, Supraincarcare &a);
	friend istream & operator >> (istream &in, Supraincarcare &a);
};
ostream & operator <<(ostream &out, Supraincarcare &a) // functia de supraincarcare a operatorului de scriere
													// acesta va fi utilizat pentru afisarea unui mesaj
{
	cout << "Vom citi datele pentru creioane si pixuri:" << endl;
	cout << endl;
	return out;
}
istream & operator >> (istream &in, Supraincarcare &a)// functia de supraincarcare a operatorului de citire
 // acesta va fi utilizat pentru citirea datelor specifice clasei de baza
{
	cout << "Dati producatorul: ";
	cin >> a.producator;
	cout << "Dati denumirea: ";
	cin >> a.denumire;
	return in;
}


void introducere(Lista &l, int x) //introducere info in noduri
{
	int Tip_derivat;
	string mina;

	string culoare;

	Produse_magazin *prodMag;

	Supraincarcare supr;

	cout << supr; // supraincarcarea scrierii
	cin >> supr; // supraincarcarea citirii	

	if (x == 0) // daca s-a ales adaugarea unui nou Scaner
	{
		creioane *Sc;
		cout << "Introduceti tip mina: ";
		cin >> mina;


		Sc = new creioane(1, supr.producator, supr.denumire, mina); //apelare constructor cu info citite
		prodMag = Sc; //cast pentru clasa de baza
		l.adaugare(prodMag); //se adauga nodul
	}
	else if (x == 1) //daca s-a ales adaugarea unei pensiuni
	{
		pix *Imprim;

		cout << "Introduceti culoare pix: ";
		cin >> culoare;

		Imprim = new pix(2, supr.producator, supr.denumire, culoare);//apelare constructor cu info citite
		prodMag = Imprim;//cast pentru clasa de baza
		l.adaugare(prodMag);//se adauga nodul
	}
}

void main() //programul principal
{
	int opt;
	Lista l;
	string culo,so;
	l.head = NULL;
	do
	{
		system("CLS");
		//meniu
		cout << "1.Adaugare creioane in lista, ordonat dupa producator.\n";
		cout << "2.Adaugare pixuri in lista, ordonat dupa producator.\n";
		cout << "3.Afisare creioane.\n";
		cout << "4.Afisare pixuri\n";
		cout << "5.Afisare dupa culoare: \n";
		cout << "6.Afisare dupa denumire: \n";
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
		case 3: l.afisare_lista();
			break;
		case 4: l.afisare_lista1();
			break;
		case 5:cin >> culo;
			l.afisare_listac(culo);
			_getch();
			break;
		case 6:cin >> so;
			l.afisare_listad(so);
			_getch;
		case 0: break;
		default:cout << "Comanda gresita!";
		}
	} while (opt != 0);
	system("pause");
	
}
