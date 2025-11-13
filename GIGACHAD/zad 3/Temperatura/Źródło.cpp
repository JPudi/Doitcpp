#include <iostream>

using namespace std;

int temperatura;

int main()
{
	cout << "Podaj temperature C: ";
	cin >> temperatura;

	if (temperatura < 0)
		cout << "Ekstremalnie zimnio ";
	else if (temperatura >= 0 && temperatura <= 25)
		cout << "Normalna temperatura";
	else
		cout << "Goraco";
}