#include <iostream>
#include <conio.h>

using namespace std;

//crearea clasei Exemplu
class Exemplu {
	int x, y;
public:
	//funcție inline intr-un mod automat
	void initializare(int a, int b)
	{
		x = a;
		y = b;
	}
	//functie de afisare
	void afisare()
	{
		cout << "Valoarea lui x:" << x << endl;
		cout << "Valoarea lui y: " << y;
	}
};
int main()
{
	//crearea unui obiect de tip Exemplu
	Exemplu ex;
	int var1, var2;
	//citirea a doua variabile intregi
	cout << "Valoarea var 1: ";
	cin >> var1;
	cout << "Valoarea var 2: ";
	cin >> var2;
	ex.initializare(var1, var2);
	ex.afisare();
	getchar();
	return 0;
}
