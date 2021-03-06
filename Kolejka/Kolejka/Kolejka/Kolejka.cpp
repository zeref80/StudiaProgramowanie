#include "pch.h"
#include <queue>
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>   
#include <vector> 
#include <cstdlib>
#include <locale.h>
#include <fstream>

using namespace std;

fstream plik;
queue < int > kolejkaLiczb;

int liczba, liczba1, liczba2, liczba3, liczba4;
int Random()
{ 
	return (rand() % 100); 
}

//pozostała część wiedzy z syllabusa

void Zaliczenie(string Zaliczenie_imie, string Zaliczenie_nazwisko, int Zaliczenie_rok_urodzenia, double Zaliczenie_srednia_ocen, double Zaliczenie_wymagana_srednia)
{
	cout << "Oto dane studenta" << endl;
	cout << "Imię: " << Zaliczenie_imie << endl;
	cout << "Nazwisko: " << Zaliczenie_nazwisko << endl;
	cout << "Rok Urodzenia: " << Zaliczenie_rok_urodzenia << endl;
	cout << "Średnia ocen: " << Zaliczenie_srednia_ocen << endl;
	if (Zaliczenie_wymagana_srednia <= Zaliczenie_srednia_ocen)
	{
		cout << "Student zaliczył " << endl << endl;
	}
	else if (Zaliczenie_wymagana_srednia > Zaliczenie_srednia_ocen)
	{
		cout << "Student nie zaliczył " << endl << endl;
	}
	else
	{
		cout << "Podano złe dane " << endl << endl;
	}
}

void Inne()
{
	//specjalnie niedefiniowanie wszystkiego na początku na cele prezentacji
	double wymaganaSrednia = 3.5;

	struct student {
		string imie;
		string nazwisko;
		int rok_urodzenia;
		double srednia_ocen;
		string tytul = "student";

	};
	struct nauczyciel {
		string imie;
		string nazwisko;
		int rok_urodzenia;
		double srednia_ocen;
		string tytul = "nauczyciel";
	};


	student student1 = { "Zbigniew","Guminski",2002,4.3 };
	nauczyciel nauczyciel1 = { "Jan","Wodecki",1970};  //nie muszę podawać wszystkich danych

	cout << "Krótki test struktury" << endl << endl;
	Zaliczenie(student1.imie, student1.nazwisko, student1.rok_urodzenia, student1.srednia_ocen, wymaganaSrednia);

	system("PAUSE");
	system("cls");

	cout << "Podaj proszę dane dla nowego student: Imie, Nazwisko, rok urodzenia, średnia jego ocen." << endl << endl;
	student student2;
	cin >> student2.imie >> student2.nazwisko >> student2.rok_urodzenia >> student2.srednia_ocen;
	Zaliczenie(student2.imie, student2.nazwisko, student2.rok_urodzenia, student2.srednia_ocen, wymaganaSrednia);

	system("PAUSE");
	system("cls");

	cout << "Przykład uniknięcia kolizji:" << endl << endl;
	cout << "Tytuł studenta:" << student1.tytul << endl; 
	cout << "Tytuł nauczyciela:" << nauczyciel1.tytul << endl; //ta sama zmienna tytul ale dzieki strukturze i podaniu ścieżki unikamy kolizji (przykład rigidbody.velocity)

	system("PAUSE");
	system("cls");

	struct data_pola_bitowe {
		unsigned int dni : 5; // 0-31
		unsigned int miesiace : 4; //0-15
		int lata : 12; //2048 p.n.e - 2047 n.e
	}; //zajmuje łącznie 21 bitów zamiast 96 bitów

	data_pola_bitowe data;
	cout << "Pola bitowe zmniejszają ilość wykorzystywanej pamięci ale nie blokują przed błędami." << endl << endl;
	data.dni = 31;  //maksymalna wartosć dla typu unsigned int na 5 bitach
	cout << data.dni << endl;
	data.dni = 32;  //przekroczony zakres
	cout << data.dni << endl;


	int wybor;
	do
	{
		system("PAUSE");
		system("cls");
		cout << "Wciśnij cyfrę 0, żeby wrócić do menu ";
		cin >> wybor;
		system("cls");
	} while (wybor != 0);

	
}

//kolejka

void TworzenieKolejki()
{
	cout << "Podaj 5 liczb: ";
	cin >> liczba >> liczba1 >> liczba2 >> liczba3 >> liczba4;

	kolejkaLiczb.push(liczba);
	kolejkaLiczb.push(liczba1);
	kolejkaLiczb.push(liczba2);
	kolejkaLiczb.push(liczba3);
	kolejkaLiczb.push(liczba4);


	cout << "Pierwsza liczba w kolejce to: " << kolejkaLiczb.front() << endl;

	cout << "Ostatnia liczba w kolejce to: " << kolejkaLiczb.back() << endl;

	cout << "W kolejce znajduje sie " << kolejkaLiczb.size() << " liczb." << endl;
	_getch();
	system("cls");
}

void display_menu_operations()
{
	int wybor;
	int ilosc_posortowanych_liczb;
	int n_element_posortowanych_liczb;
	int czestotliwosc_count;
	int ilosc_elementow_do_zerowania;
	int ilosc_zerowania = 0;

	int tabint[] = { liczba, liczba1, liczba2, liczba3, liczba4 };


	vector<int> vektor(tabint, tabint + 5);

	auto result = minmax_element(vektor.begin(), vektor.end());

	do
	{
		cout << "Co chcesz wyświetlić?" << endl;
		cout << "1.Sortowanie calosci" << endl;  
		cout << "2.Sortowanie pierwszych wybranych paru liczb" << endl; 
		cout << "3.Sortowanie n-tego elementu" << endl; 
		cout << "4.Sortowanie poprzez permutacje" << endl; 
		cout << "5.Warości min-max" << endl; 
		cout << "6.Liczenie ile razy pojawiła się dana liczba" << endl; 
		cout << "7.Wygeneruj nowy zespoł liczb" << endl; //
		cout << "8.Wyświetl liczby" << endl; //
		cout << "9.Dodaj liczby z pamięci podręcznej do kolejki." << endl;
		cout << "10. Wyzeruj kolejkę" << endl;
		cout << "11. Zapisz kolejkę do pliku" << endl;
		cout << "12. Wróć do menu" << endl;
		cout << "Wybieram : ";
		cin >> wybor;
		system("cls");

		queue<int> kopiaKolejki = kolejkaLiczb;
		switch (wybor)
		{
		case 1:
			sort(vektor.begin(), vektor.begin() + kolejkaLiczb.size());
			for (vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
				cout << ' ' << *it;
			cout << '\n';  //dziala
			break;
		case 2:

			cout << "Ile pierwszych liczb chcesz posortować?" << endl;
			cin >> ilosc_posortowanych_liczb;			

			partial_sort(vektor.begin(), vektor.begin() + ilosc_posortowanych_liczb, vektor.end());
			for ( vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
				 cout << ' ' << *it;
			 cout << '\n'; //dziala 
			break;
		case 3:
			cout << "Który element usortować?" << endl;
			cin >> n_element_posortowanych_liczb;
			nth_element(vektor.begin(), vektor.begin() + n_element_posortowanych_liczb, vektor.end());
			for ( vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
				 cout << ' ' << *it; //nie jestem pewien czy działa? Bo spełnia funkcje nth_element ale również sortuje całościowo
			 cout << '\n';
			break;
		case 4:
			do {
				prev_permutation(vektor.begin(), vektor.end());
			} while (!is_sorted(vektor.begin(), vektor.end()));
			for (vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
				cout << ' ' << *it;			//działa
			break;
		case 5: 
			cout << "Minimalnym elementem jest " << *min_element(vektor.begin(), vektor.end());
			cout << " na pozycji " << (min_element(vektor.begin(), vektor.end()) - vektor.begin()) << '\n';
			cout << "Maksymalnym elementem jest " << *max_element(vektor.begin(), vektor.end());
			cout << " na pozycji " << (max_element(vektor.begin(), vektor.end()) - vektor.begin()) << '\n';
			/*
			cout << "Minimalnym elementem jest " << *result.first;
			cout << " na pozycji " << (result.first - vektor.begin()) << '\n';
			cout << "Maksymalnym elementem jest " << *result.second;
			cout << " na pozycji " << (result.second - vektor.begin()) << '\n';  //pamięć podręczna
			*/
			break;
		case 6:
			cout << "Częstotliwość jakiej liczby zmierzyć?" << endl;
			cin >> czestotliwosc_count;
			 cout << czestotliwosc_count << "pojawia się " << count(vektor.begin(), vektor.end(), czestotliwosc_count) << " razy.\n";
			break;
		case 7:
			generate(vektor.begin(), vektor.end(), Random);
			for ( vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
				 cout << ' ' << *it;  //działa
			 cout << '\n';

			break;
		case 8:

			while (!kolejkaLiczb.empty()) {
				cout << " " << kolejkaLiczb.front();
				kolejkaLiczb.pop();
			}
			kolejkaLiczb = kopiaKolejki;
			/*
			for (vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
				cout << ' ' << *it;  //działa
				*/
			break;
		case 9:
			kolejkaLiczb.push(vektor[0]);
			kolejkaLiczb.push(vektor[1]);
			kolejkaLiczb.push(vektor[2]);
			kolejkaLiczb.push(vektor[3]);
			kolejkaLiczb.push(vektor[4]);
			cout << "Dane zostały wprowadzone do kolejki " << '\n';  //działa
			cout << "W kolejce znajduje sie " << kolejkaLiczb.size() << " liczb." << endl;
			break;
		case 10:
			while (kolejkaLiczb.empty() == false)
			{
				kolejkaLiczb.pop();
			}			
			cout << "Kolejka została wyzerowana" << '\n';
			break;
		case 11:
			plik.open("ZapisKolejki.txt", ios::out | ios::app);

			if (plik.good())
			{
				while (!kolejkaLiczb.empty()) {
					plik << " " << kolejkaLiczb.front();
					kolejkaLiczb.pop();
				}
				plik << endl;
				cout << "Dane zostały pomyślnie zapisane " << '\n';  
			}
			else
			{
				cout << "Błąd zapisu danych " << '\n';  
			}
			plik.close();

			kolejkaLiczb = kopiaKolejki;

			break;		
		case 12:
			break;
		}
		system("PAUSE");
		system("cls");
	} while (wybor != 12);

}

//główne menu

void display_menu()
{
	int wybor;
	do
	{
		cout << "*******************GLOWNE MENU********************" << endl;
		cout << "1.Kolejka " << endl;
		cout << "2.Reszta materiału z wykazu" << endl;
		cout << "3.Wyjscie z programu." << endl;
		cout << "Wybieram : ";
		cin >> wybor;
		system("cls");


		switch (wybor)
		{
		case 1:
			TworzenieKolejki();
			display_menu_operations();
			break;
		case 2:
			Inne();
			break;
		case 3:
			cout << "Wyjscie z programu." << endl;
			break;
		}
		system("PAUSE");
		system("cls");
	} while (wybor != 3);

}


int main()
{
	setlocale(LC_CTYPE, "Polish");
	display_menu();

	return 0;
}



/*zakres wiedzy - syllabus
Dynamiczne struktury danych (kolejka)
Implementacja wybranych algorytmów sortowania tablic
Złożoność obliczeniowa – porównanie wybranych algorytmów sortowania
Zapis danych z plików.
Dynamiczna alokacja pamięci.
Struktury, pola bitowe
Przegląd wybranych bibliotek.
Szablony funkcji
Inne(wartości pseudolosowe, pętle, tablice, wskaźniki, wektory etc)*/