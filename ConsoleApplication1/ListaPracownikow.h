#pragma once
#include "pracownik.h"
#include<fstream>
#include <iostream>
#include <cstring>

class ListaPracownikow
{
private:
    Pracownik *m_pPoczatek; // Wskaźnik na początek listy
    int m_nLiczbaPracownikow; // Liczba pracowników w liście

public:
    // Konstruktor domyślny
    ListaPracownikow();

    // Destruktor
    ~ListaPracownikow();

    // Dodaje pracownika do listy
    void Dodaj(const Pracownik &p);

    // Usuwa pracownika z listy
    void Usun(const Pracownik &wzorzec);

    // Wyświetla wszystkich pracowników
    void WypiszPracownikow() const;

    // Wyszukuje pracownika na podstawie nazwiska i imienia
    const Pracownik *Szukaj(const char *nazwisko, const char *imie) const;

	//Zapisuje pracowników do pliku
	void ZapiszDoPliku(const char* nazwaPliku) const;
	// Wczytuje pracowników z pliku
    void OdczytZPliku(const char* nazwaPliku);
};
