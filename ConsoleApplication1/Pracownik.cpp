#include "Pracownik.h"
#include "Data.h"
#include <iostream>

using namespace std;

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesi¹c, int rok) : m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesi¹c, rok), m_nIDZatrudnienia(m_NastepneID++)
{
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	if (this != &wzor){
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
		}
	return *this;
	
}

Pracownik::Pracownik(const Pracownik& wzor, bool kopiujID)
	: m_Imie(wzor.m_Imie), m_Nazwisko(wzor.m_Nazwisko), m_DataUrodzenia(wzor.m_DataUrodzenia),
	m_nIDZatrudnienia(kopiujID ? wzor.m_nIDZatrudnienia : m_NastepneID++),
	m_pNastepny(nullptr), m_pPoprzedni(nullptr) {}

const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char* nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << " ";
	m_Nazwisko.Wypisz();
	cout << " ";
	m_DataUrodzenia.Wypisz();
	cout << " ID: "<< m_nIDZatrudnienia;
	cout << endl;
}

void Pracownik::Wpisz()
{
	cout << "Podaj imie: ";
	m_Imie.Wpisz();
	cout << "Podaj nazwisko: ";
	m_Nazwisko.Wpisz();
	cout << "Podaj date urodzenia: ";
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	int wynik = SprawdzNazwisko(wzorzec.Nazwisko());
	if (wynik != 0) {
		return wynik;
	}
	wynik = SprawdzImie(wzorzec.Imie());
	if (wynik != 0) {
		return wynik;
	}
	wynik = m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
	if (wynik != 0) {
		return wynik;
	}
}
int Pracownik::m_NastepneID = 1;

