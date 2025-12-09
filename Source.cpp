// g³ówny plik z menu pacjentów
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;


struct Pacjent
{
    string imie, nazwisko, pesel, nrtel;
};
struct Wizyta
{
    string peselPacjenta, data, godzina, celWizyty;
};

void wczytajPacjentow(vector<Pacjent>& baza); // Wczytywanie pacjentow z pliku
void dodajPacjenta(vector<Pacjent>& baza); // Dodawanie nowego pacjenta
void wypiszPacjentow(vector<Pacjent>& baza); // Wypisywanie listy pacjentow
void menuPacjenci(vector<Pacjent>& baza); // Menu pacjentow
void wyszukajPacjenta(const vector<Pacjent>& baza); // Wyszukiwanie pacjenta

void wczytajWizyty(vector<Wizyta>& baza); // Wczytywanie wizyt z pliku
void menuWizyta(vector<Wizyta>& baza); // Menu wizyt
void dodajWizyte(vector<Wizyta>& baza); // Dodawanie wizyty
void usunWizyte(vector<Wizyta>& baza); // Usuwanie wizyty
string login, haslo; // Dane logowania
char klawisz; // Zmienna do wyboru opcji w menu

int main()
{
    vector<Pacjent> bazaPacjentow; // Baza pacjentow
    wczytajPacjentow(bazaPacjentow); // Wczytanie pacjentow z pliku przy starcie programu
	vector<Wizyta> bazaWizyt; // Baza wizyt
	wczytajWizyty(bazaWizyt); // Wczytanie wizyt z pliku przy starcie programu
    int proby = 0;
    bool zalogowano = false;

    while (proby < 3 && !zalogowano) // Maksymalnie 3 proby logowania
    {
        cout << "Podaj login: ";
        cin >> login;
        cout << "Podaj haslo: ";
        cin >> haslo;

        if (login == "Jan" && haslo == "Pudzisz") // Sprawdzenie poprawnosci danych logowania
        {
            zalogowano = true;
            do // G³ówne menu programu
            {
                system("cls");
                cout << "Zalogowany uzytkownik: " << login << endl;
                cout << "===== GABINET LEKARSKI =====" << endl;
                cout << "1. PACJENCI (Menu)" << endl;
                cout << "2. Umow wizyte" << endl;
                cout << "3. Wyswietl terminarz" << endl;
                cout << "4. Dodaj notatke do historii pacjenta" << endl;
                cout << "5. Raport dnia" << endl;
                cout << "6. Zapisz/Wczytaj" << endl;
                cout << "7. Wyjdz" << endl;
                cout << "---------------------------" << endl;
                cout << "Wybierz opcje: ";

                cin >> klawisz;
                cout << endl;

                switch (klawisz) // Obs³uga wyboru opcji w menu
                {
                case '1':
                    menuPacjenci(bazaPacjentow);
                    break;
                case '2':
                    cout << "-> Wybrano: Umow wizyte" << endl;
                    menuWizyta(bazaWizyt);
                    break;
                case '3':
                    cout << "-> Wybrano: Wyswietl terminarz" << endl;
                    break;
                case '4':
                    cout << "-> Wybrano: Dodaj notatke" << endl;
                    break;
                case '5':
                    cout << "-> Wybrano: Raport dnia" << endl;
                    break;
                case '6':
                    cout << "-> Wybrano: Zapisz/Wczytaj" << endl;
                    break;
                case '7':
                    cout << "Wychodzenie..." << endl;
                    break;
                default:
                    cout << "Nieznana opcja!" << endl;
                }

                if (klawisz != '7')
                {
                    cout << endl;
                    system("pause");
                }

            } while (klawisz != '7'); // Koniec g³ównego menu
        }
        else // Niepoprawne dane logowania
        {
            cout << "Niepoprawny login lub haslo" << endl;
            proby++;
        }
    }

    if (!zalogowano) // Po 3 nieudanych probach logowania
    {
        cout << "Odmowa dostepu!!!" << endl;
    }

    return 0;
}

void menuPacjenci(vector<Pacjent>& baza) // Menu pacjentow
{
    char klawiszPodmenu;
    bool powrot = false;

    do
    {
        system("cls");
        cout << ">>> MENU: PACJENCI <<<" << endl;
        cout << "1. Dodaj nowego pacjenta" << endl;
        cout << "2. Wypisz liste pacjentow" << endl;
        cout << "3. Wyszukiwanie pacjentow" << endl;
        cout << "4. POWROT do Menu Glownego" << endl;
        cout << "------------------------" << endl;
        cout << "Wybor: ";
        cin >> klawiszPodmenu;

        switch (klawiszPodmenu)
        {
        case '1':
            dodajPacjenta(baza);
            system("pause");
            break;
        case '2':
            wypiszPacjentow(baza);
            system("pause");
            break;
        case '3':
            wyszukajPacjenta(baza);
            system("pause");
            break;
        case '4':
            powrot = true;
            break;
        default:
            cout << "Nieznana opcja." << endl;
            system("pause");
            break;
        }

    } while (!powrot);
}

void wczytajPacjentow(vector<Pacjent>& baza) // Wczytywanie pacjentow z pliku
{
    Pacjent p;
    ifstream plik("Dane/Pacjenci.csv");
    if (plik)
    {
        while (getline(plik, p.imie, ','))
        {
            getline(plik, p.nazwisko, ',');
            getline(plik, p.pesel, ',');
            getline(plik, p.nrtel);
            baza.push_back(p);
        }
        plik.close();
    }
}

void dodajPacjenta(vector<Pacjent>& baza) // Dodawanie nowego pacjenta
{
    Pacjent p;
    cout << "--- DODAWANIE PACJENTA ---" << endl;
    cout << "Podaj imie: "; cin >> p.imie;
    cout << "Podaj nazwisko: "; cin >> p.nazwisko;
    cout << "Podaj PESEL: "; cin >> p.pesel;
    cout << "Podaj nr telefonu: "; cin >> p.nrtel;

    ofstream plik("Dane/Pacjenci.csv", std::ios::app);
    if (plik.good())
    {
        plik << p.imie << "," << p.nazwisko << "," << p.pesel << "," << p.nrtel << endl;
        plik.close();
        baza.push_back(p);
        cout << "[SUKCES] Dodano pacjenta." << endl;
    }
    else
    {
        cout << "[BLAD] Nie udalo sie otworzyc pliku." << endl;
    }
}

void wypiszPacjentow(vector<Pacjent>& baza) // Wypisywanie listy pacjentow
{
    cout << "--- LISTA PACJENTOW ---" << endl;
    if (baza.empty())
    {
        cout << "Brak pacjentow w bazie." << endl;
        return;
    }
    sort(baza.begin(), baza.end(), [](const Pacjent& a, const Pacjent& b) {
        if (a.nazwisko != b.nazwisko)
            return a.nazwisko < b.nazwisko;
        else
            return a.imie < b.imie;
        });
    for (int i = 0; i < baza.size(); i++)
    {
        cout << i + 1 << ". " << baza[i].imie << " " << baza[i].nazwisko << " (PESEL: " << baza[i].pesel << ")" << " Numer telefonu: " << baza[i].nrtel << endl;
    }
}

void wyszukajPacjenta(const vector<Pacjent>& baza) // Wyszukiwanie pacjenta
{
    if (baza.empty())
    {
        cout << "Baza jest pusta." << endl;
        return;
    }
    string fraza;
    cout << "Wyszukiwanie Pacjenta" << endl;
    cout << "Podaj nazwisko lub nr PESEL: ";
    cin >> fraza;
    bool znaleziona = false;
    cout << "Wyniki dla: " << fraza << endl;
    for (int i = 0; i < baza.size(); i++)
    {
        if (baza[i].nazwisko == fraza || baza[i].pesel == fraza)
        {
            cout << "ZNALEZIONO: " << baza[i].imie << " " << baza[i].nazwisko
                << " | PESEL: " << baza[i].pesel
                << " | Tel: " << baza[i].nrtel << endl;
            znaleziona = true;
        }
    }

    if (!znaleziona)
    {
        cout << "Nie znaleziono nikogo o takich danych." << endl;
    }
}
void menuWizyta(vector<Wizyta>& baza) // Menu wizyt
{
    char klawiszmenuwizyty;
    bool powrot = false;
    do
    {
        system("cls");
        cout << ">>> MENU: WIZYTY <<<" << endl;
        cout << "1. Wczytaj wizyte" << endl;
        cout << "2. Dodaj wizyte" << endl;
        cout << "3. Usun wizyte" << endl;
        cout << "4. POWROT do Menu Glownego" << endl;
        cout << "------------------------" << endl;
        cout << "Wybor: ";
        cin >> klawiszmenuwizyty;

        switch (klawiszmenuwizyty)
        {
        case '1':
            wczytajWizyty(baza);
            system("pause");
            break;
        case '2':
            dodajWizyte(baza);
            system("pause");
            break;
		case '3':
			usunWizyte(baza);
        case '4':
            powrot = true;
            break;
        default:
            cout << "Nieznana opcja." << endl;
            system("pause");
            break;
        }
	} while (!powrot);

}
void dodajWizyte(vector<Wizyta>& baza)
{
	cout << "Dodawanie wizyty" << endl;
}

void usunWizyte(vector<Wizyta>& baza)
{
	cout << "Usuwanie wizyty" << endl;
}

void wczytajWizyty(vector<Wizyta>& baza) // Wczytywanie wizyt z pliku
{
    Wizyta w;
    ifstream plik("Dane/Wizyty.csv");
    if (plik)
    {
        while (getline(plik, w.peselPacjenta, ','))
        {
            getline(plik, w.data, ',');
            getline(plik, w.godzina, ',');
            getline(plik, w.celWizyty);
            baza.push_back(w);
        }
        plik.close();
    }
}

/*
struct Pacjent
{
    std::string imie, nazwisko, pesel, nrtel;
};

int main()
{
    std::vector<Pacjent> pacjent;
    Pacjent p;
    std::ifstream plik("Dane/Pacjenci.csv");
    if (plik)
    {
        while (getline(plik, p.imie, ','))
        {
            getline(plik, p.nazwisko, ',');
            getline(plik, p.pesel, ',');
            getline(plik, p.nrtel);
            pacjent.push_back(p);
        }
        plik.close();
    }
    else
        std::cerr << "Blad otwarcia pliku";

    for (int i = 0; i < pacjent.size(); i++)
    {
        std::cout << pacjent[i].imie << " " << pacjent[i].nazwisko << " " << pacjent[i].pesel << " " << pacjent[i].nrtel << std::endl;
    }

}
*/