#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
     int nr;
    cout << "Valoare numarului intreg este: ";
    cin >> nr;
    // declararea și initializarea variabilelor pentru suma și produs
    int s = 0, p = 1;
    // folosirea instructiunii while pentru citirea numerelor pana la intalnirea numarului 0   
    while (nr != 0)
    {
        //verificarea numarului daca este numar par
        if (nr % 2 == 0)
	 s = s + nr;
	else
	  p = p * nr;
        cout << "Valoare numarului intreg este: "; cin >> nr;
     }
     cout << "Suma numerelor pare este: " << s << endl;
     cout << "Produsul numerelor impare este: " << p;
     getchar();
    return 0;
}
