#include <iostream>

using namespace std;
string login, password;

int main()
{
	cout << "Podaj login: ";
	cin >> login;
	cout << "Podaj haslo: ";
	cin >> password;

	if (login == "admin" && password == "admin123")
	{
		cout << "Poprawne dane";
	}
	else
		cout << "Niepoprawne dane";

}