#include<iostream> 
#include<conio.h> 
#include<string> 
#include<stdio.h>

using namespace std;

class monitor {
public:
	string producator;
	int pret;
	int diagonala;

	monitor(string a, int t, int i) 
	{
		producator = a;
		pret = t;
		diagonala = i;
	};
	virtual void display() {};
};

class lcd :public monitor {
	int timp;
	string tip; 
	int conectori; 
	lcd *head; 
	lcd *next;

public:
	lcd (string a, int t, int i, int nr, string l, int an): monitor (a, t, i) 
	{
		head = NULL;
		tip = l; 
		timp = nr; 
		conectori = an;
	}

	void display(); 
	void adaugare();
	void sterge();
	void cautare();
	void ordonare();
};

class led :public monitor {
	string form; 
	string ilum; 
	string boxe;
	led *head;
	led *next;
public:
	led(string a, int t, int i, string fo,string il,string bo) :monitor(a, t, i) 
	{
		head = NULL;
		form = fo;
		ilum = il;
		boxe = bo;

	}

	void display1(); 
	void adaugare1();
	void sterge1();
	void cautare1();
	void ordonare1();
};

void lcd::adaugare() 
{
	string producator;
	int pret;
	int diagonala;
	int timp;
	string tip;
	int conectori;
	lcd *head;
	lcd *next;
	 
	cout << "Producator: "; cin >> producator;
	cout << "Diagonala: "; cin >> diagonala;
	cout << "Pret: "; cin >> pret;
	cout << "Timp raspuns: "; cin >> timp;
	cout << "Tip ecran: "; cin >> tip;
	cout << "Conectori :";cin >> conectori;
	lcd *p = new lcd(producator, diagonala, pret ,timp, tip, conectori); p->next = head;
	head = p;
}
void lcd::display() 
{
	lcd *p = head; 
	while (p != NULL) 
	{
		cout << "----------------------------\n"; 
		cout << "Producator:" << p->producator << endl; 
		cout << "Diagonala: " << p->diagonala << endl;
		cout << "Pret: " << p->pret << endl; 
		cout << "Timp raspuns: " << p->timp << endl; 
		cout << "Tip ecran " << p->tip << endl;
		cout << "Conectori " << p->conectori << endl; 
		cout << "----------------------------\n";
		p = p->next;
	}
}
void lcd::sterge()
{
	cout << "Sterge producatorul: ";
	string val;
	cin >> val;
		lcd *c, *a;
		c = head;
		
		if (head->producator == val)
		{
			
			a = head;
			
			head = head->next;
			
			delete a;
		}
		
		else
		{
		
			while (c->next->producator != val && c)
				c = c->next;
			
			a = c->next;
			c->next = a->next;
			
			if (a->next==NULL)
				c->next = NULL;
			
			delete a;
		}
	}
void lcd::cautare()
{
		int g = 0;
		cout << "Dati producator cautat : ";
		string tit;
		cin >> tit;
		lcd *u;
		u = head;
		if (head->producator==tit) {
			cout << head->producator << " " << head->diagonala << " " << head->pret<<" " << head->timp << " "<< head->tip   <<" "<<head->conectori << endl;
			g = 1;
		}
		else
			while (u != NULL && g == 0) {
				if (u->producator == tit) {
					cout << head->producator << " " << head->diagonala << " " << head->pret<<" " << head->timp<<" " << head->tip << " "<< head->conectori << endl;
					g = 1;
				}
					
					u = u->next;
				
			}
	}





void led::adaugare1() 
{
	string producator;
	int pret;
	int diagonala;
	string form;
	string ilum;
	string boxe;

	cout << "Producator: "; cin >> producator;
	cout << "Diagonala: "; cin >> diagonala;
	cout << "Pret: "; cin >> pret;
	cout << "Format ecran: "; cin >> form;
	cout << "Iluminat: "; cin >> ilum;
	cout << "Are boxe :";cin >> boxe;

	led *p = new led(producator, diagonala, pret, form,ilum,boxe); p->next = head;
	head = p;
}



void led::display1() 
{
	led *p = head;
	while (p != NULL) 
	{
		cout << "------------------------------\n"; 
		cout << "Producator: "; cin >> producator;
		cout << "Diagonala: "; cin >> diagonala;
		cout << "Pret: "; cin >> pret;
		cout << "Format ecran: ";cout << p->form << endl;
		cout << "Iluminat: "; cout << p->ilum;
		cout << "Are boxe: ";cout << p->boxe;
		cout << "----------------------------\n";
		p = p->next;
	}
}
void led::sterge1()
{
	cout << "Sterge producatorul: ";
	string val;
	cin >> val;
	led *c, *a;
	c = head;

	if (head->producator == val)
	{

		a = head;

		head = head->next;

		delete a;
	}

	else
	{

		while (c->next->producator != val && c)
			c = c->next;

		a = c->next;
		c->next = a->next;

		if (a->next == NULL)
			c->next = NULL;

		delete a;
	}
}
void led::cautare1()
{
	int g = 0;
	cout << "Dati producator cautat : ";
	string tit;
	cin >> tit;
	led *u;
	u = head;
	if (head->producator == tit) {
		cout << head->producator << " " << head->diagonala << " " << head->pret <<" "<< head->form<<" " << head->ilum << " " << head->boxe<< endl;
		g = 1;
	}
	else
		while (u != NULL && g == 0) {
			if (u->producator == tit) {
				cout << head->producator << " " << head->diagonala << " " << head->pret<<" " << head->form<<" " << head->ilum << " " << head->boxe << endl;
				g = 1;
			}
			u = u->next;

		}
}


int main() 
{
	unsigned opt;
	char autor[30];
	lcd *c = new lcd(" ", 0, 0, 0," ",0); 
	led *o = new led(" ", 0, 0, " "," "," ");

	do 
	{
		cout << "1.Adaugare monitor LCD.\n"; 
		cout << "2.Adaugare monitor LED.\n"; 
		cout << "3.Afisare Monitor LCD.\n"; 
		cout << "4.Afisare monitoare LED.\n";
		cout << "5.Sterge monitor LCD\n";
		cout << "6.Sterge monitor LED\n";
		cout << "7.Cautare monitor LCD\n ";
		cout << "8.Cautare monnitor LED\n";
		cout << "Ordonare LCD\n";
		cout << "Ordonare LED\n";
		cout << "9.Iesire.\n";
		cout << "Opt dvs: "; 
		cin >> opt; 
		switch (opt) 
		{
			case 1: c->adaugare(); 
				break;
			case 2: o->adaugare1(); 
				break;
			case 3: c->display(); 
				break;
			case 4: o->display1(); 
				break;
			case 5:
				c->sterge;
				break;
			case 6:
				o->sterge1;
				break;
			case 7: c->cautare;
				break;
			case 8: o->cautare1;
				break;

			case 9:
				exit(0);
				break;
		}
	}while (opt != 5); 
	getch();
	return 0;
}


