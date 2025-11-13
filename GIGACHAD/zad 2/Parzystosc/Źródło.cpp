#include <iostream>

using namespace std;

int liczba;

int main()
{
	cout << "Podaj liczbe: ";
	cin >> liczba;
	if (liczba % 2 == 0)
	{
		cout << "Liczba " << liczba << " jest parzysta";
	}
	else
	{
		cout << "Liczba " << liczba << " jest nieparzysta";
	}
	return 0;
}