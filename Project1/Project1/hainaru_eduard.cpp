#include<iostream>
#include<fstream>
#include<list>
#include<string.h>
#include<iterator>

class student() {
	private
		string nume;
	int an;
	int poo;

	int tp;
	int ipc;
	public
		student(string nume, int an, int poo,  int tp,int ipc) {
		this->nume = nume;
		this->an = an;
		this->poo = poo;
	
		this->tp = tp;
		this->ipc = ipc;
	}
	afisare() {
		cout << "Nume: " << nume << " \n";
		cout << "An": << an << " \n";
		cout << "Medii : IPC " << ipc << " poo " << poo << " tp" << tp;
	}

	template <class T*> friend class lista;
}
void cit_fisier(student* b)
{
	
	student* c;
	ifstream f;
	string nume;
	int an,ipc, tp, poo;
	
	f.open("studenti.txt");
	while (!f.eof()) {
	
			f >> nume;
			f >> an;
			f >> ipc;
			f >> tp;
			f >> poo;
			
			c = new student(nume, an, poo, tp, ipc);
			
			f.ignore(1000, '\n');
		}
	
	f.close();
}

istream& operator >> (istream& in, student*& p)
{
	string nume;
	int an,ipc, tp, poo;
	cout << endl << "Introduceti Nume: " << endl;in >> nume;
	cout << "An "; in >> an;
	cout << "IPC "; in >> ipc;
	cout << "tp: ";in >> tp;
	cout << "poo"; in >> poo;
	
	p = new student(nume, an, poo,tp,ipc);
	return in;
}

template <class T>
void maxim(list <T*>&lista) {
float m;



}

template <class T>
void introducere(list<T*>& lista)
{
	T* el;
	cin >> el; 
	lista.push_front(element);


	void main() 
	{
		int opt;
		
		list<student*> stud;
		
		do
		{
			system("CLS");
			//meniu
			cout<< "1.Adaugare student \n";
			cout<< "2.Citire.\n";
			cout<< "3.Media student.\n";
			cout<< "4.Media maxima.\n";
			cout<< "0.Iesire.\n";
			cout<< "Dati optiunea dvs: ";
			cin>>opt;
			//apelare functii in functie de optiunea aleasa
			switch (opt)
			{
			case 1: cit_fisier(stud);
				break;
			case 2: introducere(stud); 
				break;
			case 3: ;
				break;
			case 4: ;
				break;
			case 0: break;
			default:cout << "Comanda gresita!";
			}
		} while (opt != 0);