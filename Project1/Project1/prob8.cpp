#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
class carti {
	char *autor;
	char *titlu;
	int imprumutat;
	carti *head;
	carti *next;
public:
	carti(char *, char *, int);
	void adaugare();
	void afisare();
	void cautare();
	void sterge();
};

carti::carti(char *a, char *t, int i)
{
	autor = new char[20];
	titlu = new char[20];
	strcpy(autor, a);
	strcpy(titlu, t);
	imprumutat = i;
	head = NULL;
}

void carti::adaugare() {
	cout << "Adaugarea unui nod la inceputul listei" << endl;
	cout << "Dati autorul: ";
	fflush(stdin);
	gets(autor);
	cout << "Dati titlul: ";
	fflush(stdin);
	gets(titlu);
	cout << "Dati starea cartii(imprumutata = 1/ neimprumutata = 0): ";
	cin >> imprumutat;
	carti *c = new carti(autor, titlu, imprumutat);
	c->next = head;
	head = c;
}

void carti::afisare()
{
	carti *c = head;
	while (c != NULL) {
		cout << "--------------" << endl;
		cout << "Autor: " << c->autor << endl;
		cout << "Titlu: " << c->titlu << endl;
		cout << "Imprumutat" << c->imprumutat << endl;
		cout << "--------------" << endl;
		c = c->next;
	}
}

void carti::cautare()
{
	int g = 0;
	cout << "Dati titlu carte cautata : ";
	char tit[20];
	gets_s(tit);
	carti *u;
	u = head;
	if (strcmp(head->titlu, tit) == 0) {
		cout << head->titlu << " " << head->autor << " " << head->imprumutat << endl;
		g = 1;
	}
	else
		while (u != NULL && g == 0) {
			if (strcmp(u->titlu, tit) == 0) {
				cout << u->titlu << " " << u->autor << " " << u->imprumutat << endl;

				u = u->next;
			}
		}
}


void carti ::sterge()
	{
		cout << "Dati titlu carte cautata : ";
		char tit[20];
		gets_s(tit);
		carti *u,*s;
		u = head;
		if (strcmp(head->titlu,tit)==0)
		{
			
			s = head;
			
			head = head->next;
		
			delete s;
		}
		
		else
		{
			
			while (strcmp(u->next->titlu,tit)!=0 && u)
				u = u->next;
		
			s = u->next;
			u->next = s->next;
		
			delete s;
		}
	
	}

int main() {
	int opt;
	carti *c = new carti(" ", " ", 0);
	do {
		cout << "1. Adaugare carte" << endl;
		cout << "2. Afisare carte" << endl;
		cout << "3.Cautare" << endl;
		cout << "4.Stergere" << endl;
		cout << "0. Iesire" << endl;
		cout << "Optiune: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			c->adaugare();
			break;
		case 2:
			c->afisare();
			break;
		case 3:
			c->cautare();
			break;
		case 4:
			c->sterge;
			break;

		}
	} while (opt != 0);
	getch();
}
