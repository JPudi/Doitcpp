#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int liczba, liczbaz, ileprob=0;

int main()
{
	cout << "Pomyslalem sobie pewna liczbe od 1 do 100 " << endl;
	srand(time(NULL));
	liczba = rand() % 100 + 1;

	while (liczbaz != liczba)
	{
		ileprob++;
		cout << "Podaj swoja liczbe: ";
		cin >> liczbaz;

		if (liczbaz == liczba)
			cout << "Zgadles liczbe" << endl;
		else if (liczbaz < liczba)
			cout << "Twoja liczba jest ponizej wymyslonej" << endl;
		else
			cout << "Twoje liczba jest powyzej wymyslonej" << endl;
	}
	cout << "Liczbe udalo ci sie zgadnac w " << ileprob << " probie" << endl;
}