#include<iostream>
#include<conio.h>
#include<string> 
using namespace std;

class Lista;  //prototipul clasei Lista

class carti  //clasa de baza Produse_magazin
{
private:
	int tip_derivat;
	string autor; 
	string titlu;
	string imprumutat; 
	carti *urm;  
public:
	carti(int t, string au,  string ti, string im) 
	{
		tip_derivat = t;
		autor = au;
		titlu = ti;
		imprumutat = im;
		urm = NULL; 
	}

	virtual void afisare() //functia de afisare elemente clasa de baza
	{
		cout << "-----------------------------------------\n";
		cout << "Autor " << autor << endl;
		cout << "Titlu: " << titlu << endl;
		cout << "Imprumutat: " << imprumutat << endl;
		
	}
	friend class Lista; //declararea clasei Lista friend la clasa Produse_magazin, pentru a se avea acces la campurile acesteia
};

class tehnice :public carti 
{
private:
	string limba; 
	int an; 
public:
	tehnice( int t,string au,  string ti, string im, string lm ,int a) :carti(t,au, ti, im) //constructor clasa derivata
	{
		limba = lm;
		an = a;
	}

	void afisare() //afisare elemente din clasa Scanere
	{
		carti::afisare(); //apelare afisare elemente din clasa de baza
		cout << "Limba: " << limba << endl;
		cout << "Anul: " << an << endl;
	}
	friend class Lista;
};

class literatura :public carti
{
private:
	
	string tip;   
public:
	literatura(int t ,string au, string ti, string im, string tp) :carti(t, au ,ti , im) //constructor
	{

		tip = tp;
	}

	void afisare() //functie afisare
	{
		carti::afisare();
		cout << "Tip: " << tip << endl;
	}
	friend class Lista;
};
///////////////////////////////////////////////////////

class Lista //clasa Lista
{
public:
	carti *head; //capul listei
	void adaugare(carti *prod); //adaugare in lista
	void afisare_lista(); //afisarea listei
	void afisare_conditionata(string soft); //afisarea unui anumit produs
	void stergere(string prod); //stergere din lista
	void afisare_conditionata1(int sot);
};

//adaugare in lista ordonata
void Lista::adaugare(carti *a)
{
	carti *p; //var p este declarata de tip Produse_magazin

	p = head; //se initializeaza cu capul listei
	if (p) //daca lista nu este vida
	{
		if (a->titlu.compare(p->titlu) < 0) //daca nodul care se adauga este mai mic decat primul nod din lista 
		{
			a->urm = head; //noul nod se leaga de primul nod
			head = a; //capul listei devine noul nod
		}
		else
		{
			while (p->urm && (p->urm->titlu.compare(a->titlu) < 0))  //se parcurge lista pana cand exista elemente si noul nod nu este mai mare decat nodul curent
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
	carti *a;

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

void introducere(Lista &l, int x) //introducere info in noduri
{
	int Tip_derivat;  
	string Autor; 

	string Titlu; 
	string  Imprumutat; 
	
	int An;  
	string  Limba; 
	string  Tip;   
	carti *prodMag;

	cout << "Introduceti autorul: ";
	cin >> Autor;
	cout << "Introduceti titlu: ";
	cin >> Titlu;
	cout << "Imprumutat sau nu: ";
	cin >> Imprumutat;
	cout << "0.Tehnic sau 1.Literatura";
	cin >> Tip_derivat;
	if (x == 0) 
	{
		tehnice *Sc;
		cout << "Introduceti limba: ";
		cin >> Limba;
		cout << "Introduceti anul: ";
		cin >> An;

		Sc = new tehnice(Tip_derivat, Autor, Titlu, Imprumutat, Limba, An); //apelare constructor cu info citite
		prodMag = Sc; //cast pentru clasa de baza
		l.adaugare(prodMag); //se adauga nodul
	}
	else if (x == 1) //daca s-a ales adaugarea unei pensiuni
	{
		literatura *Imprim;

		cout << "Introduceti tipul imprimantei: ";
		cin >> Tip;
		Imprim = new literatura(Tip_derivat, Autor, Titlu, Imprumutat, Tip);//apelare constructor cu info citite
		prodMag = Imprim;//cast pentru clasa de baza
		l.adaugare(prodMag);//se adauga nodul
	}
}

void Lista::stergere(string prod) //stergere element din lista
{
	carti *p, *q;
	p = q = head;
	if (p)
	{
		while (p && p->titlu.compare(prod) != 0) //cat timp nu s-a gasit nodul care se doreste a fi sters
		{
			q = p; //se inainteaza in lista cu cei 2 pointeri
			p = p->urm;
		}
		if (p) //daca lista nu este goala
		{
			if (p != q) //daca nu este un singur nod in lista
			{
				q->urm = p->urm; //se realizeaza legaturile dintre nodurile care raman
				delete p; //se sterge nodul dorit
			}
			else
			{
				head = p->urm; //se sterge capul liste daca nodul de sters este capul liste si capul devine urm nod
				delete p;
			}
		}
		else
			cout << "Titlul nu exista in lista!";
	}
	else
		cout << "Lista este vida!";
}

void Lista::afisare_conditionata(string soft) 
{
	carti *produMag;
	literatura *Sc;


	produMag = head;
	if (!produMag)
		cout << "Lista este vida!";
	else
		while (produMag) //daca lista nu este vida
		{
			
			{
				Sc = (literatura *)produMag;
				if (Sc->tip.compare(soft) == 0)
				{
					produMag->afisare();
				}
			}
			produMag = produMag->urm; //se inainteaza in lista
		}
}


void Lista::afisare_conditionata1(int sot)
{
	carti *prodMag;
	tehnice *Sb;
	int max = 0;

	prodMag = head;
	if (!prodMag)
		cout << "Lista este vida!";
	else
		while (prodMag) //daca lista nu este vida
		{

			{
				Sb = (tehnice*)prodMag;
				if (Sb->an>=sot)
				{max=Sb->an;
					prodMag->afisare();
				}
			}
			prodMag = prodMag->urm; //se inainteaza in lista
		}
}


void main() //programul principal
{
	int opt,sot;
	Lista l;
	l.head = NULL;
	string soft;
	string produc;
	do
	{
		system("CLS");
		//meniu
		cout << "1.Adaugare carti tehnice in lista, ordonat dupa Titlu.\n";
		cout << "2.Adaugare carti literatura in lista, ordonat dupa Titlu.\n";
		cout << "3.Afisare carti din magazin.\n";
		cout << "4.Afisare carti cu un anumit Tip citit de la tastatura.\n";
		cout << "5.Stergere carti dupa Titlu.\n";
		cout << "6. Afisare dupa an minim: \n";
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
		case 4:
			cout << "Introduceti numele tipului: ";
			cin >> soft;
			l.afisare_conditionata(soft);
			_getch();
			break;
		case 5:
			cout << "Introduceti Titlul care doriti sa il stergeti: ";
			cin >> produc;
			l.stergere(produc);
			cout << "Apasati o tasta pt continuare...";
			_getch();
			break;
		case 6:
			cout << "Introduceti anul: ";
			cin >> sot;
			l.afisare_conditionata1(sot);
			_getch();
			break;
		case 0: break;
		default:cout << "Comanda gresita!";
		}
	} while (opt != 0);
}

