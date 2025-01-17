#include "Kierownik.h"

Kierownik::Kierownik() :m_NazwaDzialu("")
{
	m_nliczbaPracownikow = 0;
}

Kierownik::Kierownik(Kierownik& wzor) :Pracownik(wzor, false), m_nliczbaPracownikow(wzor.m_nliczbaPracownikow)
{
}

Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
	if (this != &wzor) {
		Pracownik::operator=(wzor);
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
	if(Pracownik::operator==(wzor) && m_NazwaDzialu == wzor.m_NazwaDzialu && m_nliczbaPracownikow == wzor.m_nliczbaPracownikow){
		return 1;
	}
	else {
		return 0;
	}
}

void Kierownik::WypiszDane()
{
	Pracownik::Wypisz();
	cout << "Nazwa dzialu: " << m_NazwaDzialu << endl;
	cout << "Liczba Pracownikow: " << m_nliczbaPracownikow << endl;
}

//Pracownik* Kierownik::KopiaObiektu() const
//{
//	//Pracownik::KopiaObiektu();
//	return
//}

ostream& operator<<(ostream& wy, const Kierownik& s)
{
	
	return wy;
}

//istream& operator>>(istream& we, Kierownik& s)
//{
//	// TODO: tu wstawiæ instrukcjê return
//}
