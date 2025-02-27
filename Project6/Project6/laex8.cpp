#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<limits>
using namespace std;
class Lista; 
class magazin 
{
private:
	int tip;
	string nume;
	int pret;
	
	magazin *urm; 
public:
	magazin(int tp, string n, int p) 
	{
		tip = tp;
		nume = n;
		pret = p;
		
		urm = NULL; 
	}
	virtual void afisare() 
	{
		cout << "-----------------------------------------\n";
		cout << "Producator: " << nume << endl;
		cout << "Pret: " << pret << endl;
		
	}
	friend class Lista; 
};
class masina :public magazin 
{
private:
	int nr_p;
	
public:
	masina(int tp, string n, int p, int s) :magazin(tp, n, p) 
	{
		nr_p = s;
		
	}
	void afisare() 
	{
		magazin::afisare(); 
		cout << "Nr programe: " << nr_p<< endl;
		
	}
	friend class Lista;
};
class aragaz :public magazin 
{
private:
	string tipa;
public:
	aragaz(int tp, string n, int p, string t) :magazin(tp, n, p) 
	{
		tipa = t;
	}
	void afisare() 
	{
		magazin::afisare();
		cout << "Tip arzator: " << tipa << endl;
		
	}
	friend class Lista;
};
class Lista 
{
public:
	magazin *head; 
	void adaugare(magazin *a);
	void afisare_lista(); 
	void scriere_fisier();
	void citire();
	void afisare_listac(string soft);
};
void Lista::afisare_listac(string soft) 
{
	magazin *produMag;
	aragaz *Sc;

	produMag = head;
	if (!produMag)
		cout << "Lista este vida!";
	else
		while (produMag) 
		{

			{
				Sc = (aragaz *)produMag;
				if (Sc->tipa.compare(soft) == 0)
				{
					produMag->afisare();
				}
			}
			produMag = produMag->urm; 
		}
}
void Lista::citire() {
	ifstream f("ListaEterogena.in");
	magazin *a;
	f >> a->tip;
	f >> a->nume;
	f >> a->pret;
	if (a->tip == 0) {
		masina* o_masina = (masina*)a;
		f >> o_masina->nr_p;
	}
	if (a->tip == 1) {
		aragaz* o_aragaz = (aragaz*)a;
		f >> o_aragaz->tipa;
	}
	f >> a->urm;
}
void Lista::scriere_fisier()
{
	ofstream fluxScriere("ListaEterogena.txt", std::ofstream::app);
	magazin* a;
	a = head; 
	if (!a)
		cout << "Lista este vida!";
	else
	{
		if (fluxScriere.is_open())
		{
			while (a)
			{
				fluxScriere << "tip: " << a->tip << endl;
				fluxScriere << "denumire: " << a->nume << endl;
				fluxScriere << "pret: " << a->pret << endl;
				
				if (a->tip == 0)
				{
					masina* o_masina = (masina*)a;
					fluxScriere << "nr stele: " << o_masina->nr_p << endl;
					
				}
				else if (a->tip == 1)
				{
					aragaz* o_aragaz = (aragaz*)a;
					fluxScriere << "tip arzator: " << o_aragaz->tipa << endl;

				}
				fluxScriere << "---------------------------------" << endl;
				a = a->urm; 
			}
			fluxScriere.close();

		}
	}

}


class MyException {
public:
	string str_what;
	int what;
	MyException() { str_what = "0"; what = 0; }
	MyException(string s, int e)
	{
		str_what = s;
		what = e;
	}
};

//adaugare in lista ordonata
void Lista::adaugare(magazin *a)
{
	magazin *p; 
	p = head; 
	if (p) 
	{
		if (a->nume > p->nume) 
		{
			a->urm = head; 
			head = a; 
		}
		else
		{
			while (p->urm && (p->urm->nume > a->nume)) 
				p = p->urm;
			a->urm = p->urm; 
			p->urm = a;
		}
	}
	else
		head = a; 
}
void Lista::afisare_lista() 
{
	magazin *a;
	a = head; 
	if (!a) 
		cout << "Lista este vida!";
	else
		while (a) 
		{
			a->afisare(); 
			a = a->urm; 
			getchar();
		}
}
void introducere(Lista &l, int x) 
{
	string nume;
	int pret;
	int nr_p;
	string tip;
	magazin *a;
	cout << "Dati numele producatorului: ";
	cin >> nume;
	try {
		while ((cout << "Dati pretul : ") && !(cin >> pret))
		{
			cout << "nu este cifra !!! \n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}



		if (pret < 0)
		{

			throw MyException("Pretul nu este pozitiv", pret);
		}
	}
	catch (MyException e) { 
		do {
			cout << "Introduceti un pret (valoare pozitiva): ";
			while ((cout << "Dati pretul : ") && !(cin >> pret))
			{
				cout << "nu este cifra !!! \n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}
		} while (pret < 0);
	}
	
	if (x == 0) 
	{
		masina *h;
		cout << "Dati numarul de programe: ";
		cin >> nr_p;
		
		h = new masina(0, nume, pret, nr_p); 
		a = h; 
		l.adaugare(a); 
	}
	else if (x == 1) 
	{
		aragaz *p;
		cout << "Dati tip arzator: ";
		cin >> tipa;
		
		p = new aragaz(1, nume, pret, tipa);
		a = p;
		l.adaugare(a);
	}
}

void main() 
{
	int opt;
	string so;
	Lista l;
	l.head = NULL;
	do
	{
		system("CLS");
		
		cout << "1.Adaugare oferta masina spalat.\n";
		cout << "2.Adaugare oferta aragaz.\n";
		cout << "3.Afisare oferte.\n";
		cout << "4.Salvare fisier. \n";
		cout << "5.Citire fisier. \n";
		cout<<"6.Aragaz cu acest tip de arzator:\n"
		cout << "0.Iesire.\n";
		cout << "Dati optiunea dvs: ";
		cin >> opt;
		
		switch (opt)
		{
		case 1: introducere(l, 0);
			break;
		case 2: introducere(l, 1);
			break;
		case 3: l.afisare_lista();
			break;
		case 4: l.scriere_fisier();
			break;
		case 5: l.citire();
			break;
		case 6: cin >> so;
			l.afisare_listac(so);
			break;
		case 0: break;
		default:cout << "Comanda gresita!";
		}
	} while (opt != 0);
}

