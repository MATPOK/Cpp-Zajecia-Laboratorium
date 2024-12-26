#include <iostream>
#include "ListaPracownikow.h"


// Wyświetla menu użytkownika
void WyswietlMenu()
{
    std::cout << "\n--- MENU ---\n";
    std::cout << "a) Dodaj nowego pracownika\n";
    std::cout << "b) Usun pracownika\n";
    std::cout << "c) Wypisz cala liste pracownikow\n";
    std::cout << "d) Wyszukaj pracownika po nazwisku i imieniu\n";
    std::cout << "e) Zapisz pracownikow w pliku\n";
    std::cout << "f) Wczytaj pracownikow z pliku\n";
    std::cout << "g) Wyjdz\n";
    std::cout << "Twoj wybor: ";
}



int main()
{
    ListaPracownikow lista; // Tworzy listę pracowników
    char wybor;
	char nazwaPliku[40] = "Pracownicy.txt";

    do
    {
        WyswietlMenu();      // Wyświetla menu
        std::cin >> wybor;   // Pobiera wybór użytkownika
        std::cin.ignore();   // Oczyszcza strumień wejścia

        switch (wybor)
        {
        case 'a': // Dodanie nowego pracownika
        {
            Pracownik nowyPracownik;
            std::cout << "Wprowadz dane nowego pracownika:\n";
            nowyPracownik.Wpisz();  // Wczytanie danych pracownika
            lista.Dodaj(nowyPracownik); // Dodanie pracownika do listy
            break;
        }
        case 'b': // Usunięcie pracownika
        {
            Pracownik wzorzec;
            std::cout << "Wprowadz dane pracownika do usuniecia:\n";
            wzorzec.Wpisz(); // Wczytanie danych pracownika
            lista.Usun(wzorzec); // Usunięcie pracownika z listy
            break;
        }
        case 'c': // Wyświetlenie listy pracowników
        {
            std::cout << "Lista pracownikow:\n";
            lista.WypiszPracownikow(); // Wyświetlenie pracowników
            break;
        }
        case 'd': // Wyszukanie pracownika
        {
            char nazwisko[40], imie[40];
            std::cout << "Podaj imie: ";
            std::cin.getline(imie, 40); // Wczytanie imienia
            std::cout << "Podaj nazwisko: ";
            std::cin.getline(nazwisko, 40); // Wczytanie nazwiska

            const Pracownik *znaleziony = lista.Szukaj(nazwisko, imie); // Wyszukanie pracownika
            if (znaleziony)
            {
                std::cout << "Znaleziono pracownika:\n";
                znaleziony->Wypisz(); // Wyświetlenie znalezionego pracownika
            }
            else
            {
                std::cout << "Nie znaleziono pracownika o podanym nazwisku i imieniu.\n";
            }
            break;
        }
        case 'e': // Zapis pracowników do pliku
        {
			lista.ZapiszDoPliku(nazwaPliku);
            break;
        }
		case 'f': // Odczyt pracowników z pliku
        {
            lista.OdczytZPliku(nazwaPliku);
            break;
        }
        case 'g': // Wyjście z programu
            std::cout << "Koniec programu.\n";
            break;
        default:
            std::cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }
    } while (wybor != 'g'); // Powtarza pętlę, dopóki użytkownik nie wybierze wyjścia

    return 0; // Zakończenie programu
}

