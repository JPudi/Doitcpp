#include <iostream>
#include <string>

using namespace std;
string haslo;
int main()
{
	cout << "Podaj haslo: ";
	cin >> haslo;

	if (haslo == "tajne123")
	{
		cout << "Dostep przyznany";
	}
	else
		cout << "Bledne haslo. Sprobuj ponownie";
	return 0;
}