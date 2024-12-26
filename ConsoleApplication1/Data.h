#pragma once
#include <iostream>
class Data
{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	void Koryguj();
public:
	Data(int d, int m, int r);
	Data();
	void Ustaw(int d, int m, int r);
	int InfoDzien() const;
	int InfoMiesiac() const;
	int InfoRok() const;
	void Wypisz() const;
	void Wpisz();
	int Porownaj(const Data& wzor) const;

	friend std::ostream& operator<<(std::ostream& wy, const Data& d);
	friend std::istream& operator>>(std::istream& we, Data& d);
};

std::ostream& operator<<(std::ostream& wy, const Data& d);
std::istream& operator>>(std::istream& we, Data& d);
