#pragma once
#include <iostream>

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
};