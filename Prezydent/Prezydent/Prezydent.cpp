#include <iostream>

using namespace std;

int wiek;

int main()
{
	cout << "Podaj twoj wiek: ";
	cin >> wiek;
	if (wiek >= 18)
	{
		cout << "Jestes pelnoletni" << endl;
	}
	else
	{
		cout << "Nie jestes pelnoletni" << endl;
	}
	if (wiek >= 35)
	{
		cout << "Mozesz byc kandydatem na prezydenta";
	}
	else
	{
		cout << "Nie mozesz byc kandydatem na prezydenta";
	}
}