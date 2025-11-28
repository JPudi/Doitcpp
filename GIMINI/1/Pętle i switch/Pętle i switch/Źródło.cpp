#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//int main()
//{
//	int suma = 0;
//	int x = 1;
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << i << endl;
//	}
//	cout << "Start" << endl;
//	while (x <= 100)
//	{
//		suma += x;
//		x++;
//	}
//	cout << suma;
//}

//int main()
//{
//	int liczba;
//	do
//	{
//		cout << "Podaj liczbe: ";
//		cin >> liczba;
//		if (liczba % 2 == 0)
//		{
//			cout << "Liczba parzysta" << endl;
//		}
//	} while (liczba % 2 == 0);
//	cout << "Sukces! Wprowadzona liczba to: " << liczba << "." << endl;
// return 0
//}

//int main()
//{
//	char numer;
//	do
//	{
//		cout << "1. Kawa   " << endl;
//		cout << "2. Herbata" << endl;
//		cout << "3. Sok    " << endl;
//		cout << "0. Koniec    " << endl;
//		cout << "Podaj pozycje: ";
//		cin >> numer;
//
//		switch (numer)
//		{
//		case '1':
//		{
//			cout << "Wybrano kawe. Cena 12 PLN" << endl;
//			break;
//		}
//		case '2':
//		{
//			cout << "Wybrano herbate. Cena 8 PLN" << endl;
//			break;
//		}
//		case '3':
//		{
//			cout << "Wybrano sok. Cena 10 PLN" << endl;
//			break;
//		}
//		case '0':
//		{
//			cout << "Koniec" << endl;
//			break;
//		}
//		default:
//			cout << "Blad! Sprobuj ponownie"<< endl;
//		}
//	} 
//	while (numer != '0');
//}

//int main()
//{
//	srand(time(NULL));
//
//	int losowa_a, losowa_b, iloczyn_1, iloczyn;
//
//	string odpowiedz;
//	const string TAK = "T";
//	do
//	{
//		losowa_a = rand() % 10 + 1;
//		losowa_b = rand() % 10 + 1;
//		iloczyn = losowa_a * losowa_b;
//
//		do
//		{
//			cout << losowa_a << " * " << losowa_b << " = ";
//			cin >> iloczyn_1;
//			if (iloczyn == iloczyn_1)
//			{
//				cout << "Brawo udalo ci sie zgadnac!!!"<<endl;
//			}
//			else
//			{
//				cout << "Bledna odpowiedz sprobuj ponownie " << endl;
//			}
//		} while (iloczyn != iloczyn_1);
//		cout << "Czy chcesz kontynuowac? (T/N)"<<endl;
//		cin >> odpowiedz;
//	} while (odpowiedz == TAK);
//	{
//		cout << "Dziekujemy za gre!";
//	}
//return 0;
//}