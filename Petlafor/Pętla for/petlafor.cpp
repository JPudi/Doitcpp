#include <iostream>
#include <windows.h>

using namespace std;

string imie;
int liczba;

int main()
{
	/*for (int i = 1; i <= 10; i++)
	{
		cout << i <<  endl;
	}*/

	/*for (int i = 15; i >= 0; i--)
	{
		Sleep(1000);
		system("cls");
		cout << i << endl;
	}
	cout << "jebut";*/

	cout << "Podaj Imie: ";
	cin >> imie;
	cout << "Podaj liczbe calkowita: ";
	cin >> liczba;

	for (int i = 1; i <= liczba; i++)
	{
		cout << i <<". " << imie << endl;
	}
	cout << "Imie " << imie << " wypisano " << liczba << " razy";
	return 0;
}