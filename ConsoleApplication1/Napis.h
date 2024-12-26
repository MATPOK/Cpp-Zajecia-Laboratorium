#pragma once
#include <iostream>
#include <cstring>

class Napis {
private:
    char* m_pszNapis; // Wska�nik na dynamicznie alokowany napis
    int m_nDl;        // D�ugo�� napisu (przydzielonej pami�ci)

public:
    // Konstruktor domy�lny
    Napis(const char* nap = "");

    // Konstruktor kopiuj�cy
    Napis(const Napis& wzor);

    // Operator przypisania
    Napis& operator=(const Napis& wzor);

    // Destruktor
    ~Napis();

    // Metody dost�powe
    const char* Zwroc() const;
    void Ustaw(const char* nowy_napis);
    void Wypisz() const;
    void Wpisz();
    int SprawdzNapis(const char* por_napis) const;

	bool operator==(const Napis& wzor) const;
    void operator+=(const char* n);

	friend std::ostream& operator<<(std::ostream& wy, const Napis& p);
	friend std::istream& operator>>(std::istream& we, Napis& p);
};
std::ostream& operator<<(std::ostream& wy, const Napis& p);
std::istream& operator>>(std::istream& we, Napis& p);