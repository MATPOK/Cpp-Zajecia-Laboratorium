#include "Kierownik.h"

using namespace std;

Kierownik::Kierownik() :m_NazwaDzialu("")
{
	m_nliczbaPracownikow = 0;
}

Kierownik::Kierownik(Kierownik& wzor) : Pracownik(wzor, false),
m_NazwaDzialu(wzor.m_NazwaDzialu),
m_nliczbaPracownikow(wzor.m_nliczbaPracownikow)
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
//	return new Kierownik(*this);
//}


ostream& operator<<(ostream& wy, const Kierownik& s)
{
	wy << static_cast<const Pracownik&>(s); // Wywo³anie operatora << klasy bazowej
	wy << "Nazwa dzialu: " << s.m_NazwaDzialu << endl;
	wy << "Liczba pracownikow: " << s.m_nliczbaPracownikow << endl;
	return wy;
}


istream& operator>>(istream& we, Kierownik& s)
{
	we >> static_cast<Pracownik&>(s); // Wywo³anie operatora >> klasy bazowej
	we >> s.m_NazwaDzialu;            // Wczytanie nazwy dzia³u
	we >> s.m_nliczbaPracownikow;     // Wczytanie liczby pracowników
	return we;
}


