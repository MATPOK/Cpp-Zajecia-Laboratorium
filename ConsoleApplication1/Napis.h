#pragma once
#include <iostream>
#include <cstring>

class Napis {
private:
    char* m_pszNapis; // WskaŸnik na dynamicznie alokowany napis
    int m_nDl;        // D³ugoœæ napisu (przydzielonej pamiêci)

public:
    // Konstruktor domyœlny
    Napis(const char* nap = "");

    // Konstruktor kopiuj¹cy
    Napis(const Napis& wzor);

    // Operator przypisania
    Napis& operator=(const Napis& wzor);

    // Destruktor
    ~Napis();

    // Metody dostêpowe
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