#pragma once
#include <iostream>
#include "Napis.h"
#include "Pracownik.h"

using namespace std;

class Kierownik: public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;
public:
	Kierownik();
	Kierownik(Kierownik& wzor);

	Kierownik& operator=(const Kierownik& wzor);
	bool operator==(const Kierownik& wzor) const;

	virtual void WypiszDane() override;
	//virtual Pracownik* KopiaObiektu()const override;


	friend ostream& operator<<(ostream& wy, const Kierownik& p);
	friend istream& operator>>(istream& we, Kierownik& p);
};
ostream& operator<<(ostream& wy, const Kierownik& s);
istream& operator>>(istream& we, Kierownik& s);

