#pragma once
#include "Napis.h"
#include "Data.h"
#include <iostream>

class Pracownik
{
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int m_NastepneID;


public:
	Pracownik(const char* im = "", const char* naz = "", int dzien = 1, int miesi�c = 1, int rok = 2000);
	Pracownik(const Pracownik& wzor, bool kopiujID=false);
	Pracownik& operator=(const Pracownik& wzor);

	const char* Imie() const;
	const char* Nazwisko() const;

	Pracownik* m_pNastepny;
	Pracownik* m_pPoprzedni;

	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);

	void Wypisz() const;
	void Wpisz();

	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const;

	bool operator==(const Pracownik& wzor) const;

	friend std::ostream& operator<<(std::ostream& wy, const Pracownik& p);
	friend std::istream& operator>>(std::istream& we, Pracownik& p);
};
std::ostream& operator<<(std::ostream& wy, const Pracownik& p);
std::istream& operator>>(std::istream& we, Pracownik& p);


