#pragma once
#include <iostream>

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
};