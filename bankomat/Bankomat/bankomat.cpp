#include <iostream>
using namespace std;


int main()
{
	/*int pinp = 1234, pin;
	cout << "Podaj PIN: ";
	cin >> pin;
	if (pin == pinp)
		cout << "PIN poprawny. Dostep do konta przyznany." << endl;
	else
		cout << "Niepoprawny PIN" << endl;
	return 0;*/

	string PIN ;
	cout << "Witamy w bankomacie. Podaj PIN: ";
	cin >> PIN;
	if (PIN == "1729")
	{
		cout << "PIN poprawny." << endl;
	}
	else 
	{
		cout << "Niepoprawny PIN." << endl;
	}
}