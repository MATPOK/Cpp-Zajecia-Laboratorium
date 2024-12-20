#include "ListaPracownikow.h"
#include <iostream>
#include <cstring>

// Konstruktor domyślny inicjalizujący pustą listę
ListaPracownikow::ListaPracownikow()
{
    m_nLiczbaPracownikow = 0; // Początkowa liczba pracowników
    m_pPoczatek = nullptr;    // Lista jest pusta, więc wskaźnik na początek to `nullptr`
}

// Destruktor zwalniający pamięć
ListaPracownikow::~ListaPracownikow()
{
    Pracownik *usun = m_pPoczatek; // Zaczyna od pierwszego elementu
    while (usun != nullptr)        // Dopóki lista nie jest pusta
    {
        Pracownik *next = usun->m_pNastepny; // Zapamiętuje wskaźnik na następny element
        delete usun;                         // Usuwa bieżący element
        m_nLiczbaPracownikow--;              // Zmniejsza licznik pracowników
        usun = next;                         // Przechodzi do kolejnego elementu
    }
}

// Dodaje pracownika do listy
void ListaPracownikow::Dodaj(const Pracownik &p)
{
    bool wasFoundInList = false;
    Pracownik *test = m_pPoczatek;

    // Sprawdza, czy pracownik już istnieje w liście
    while (test != nullptr)
    {
        if (test->Porownaj(p) == 0) // Jeśli pracownik istnieje, ustawia flagę
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }

    // Jeśli pracownika nie ma na liście, dodaje go
    if (!wasFoundInList)
    {
        Pracownik *nowy = new Pracownik(p, true); // Tworzy nowego pracownika
        nowy->m_pNastepny = nullptr;       // Ustawia `nullptr` jako następny element
        nowy->m_pPoprzedni = nullptr;       // Ustawia `nullptr` jako poprzedni element
        if (m_nLiczbaPracownikow == 0)     // Jeśli lista jest pusta
        {
            m_pPoczatek = nowy;            // Nowy element staje się początkiem
        }
        else
        {
            Pracownik *last = m_pPoczatek;
            while (last->m_pNastepny != nullptr) // Znajduje ostatni element listy
            {
                last = last->m_pNastepny;
            }
            last->m_pNastepny = nowy;     // Dodaje nowy element na końcu
            nowy->m_pPoprzedni = last;     // Łączy wstecz z poprzednim elementem
        }
        m_nLiczbaPracownikow++;           // Zwiększa liczbę pracowników
    }
}

// Usuwa pracownika z listy
void ListaPracownikow::Usun(const Pracownik &wzorzec)
{
    Pracownik *test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez całą listę
    {
        if (test->Porownaj(wzorzec) == 0) // Szuka pracownika do usunięcia
        {
            Pracownik *next = test->m_pNastepny;
            Pracownik *prev = test->m_pPoprzedni;
            if (test == m_pPoczatek)
                m_pPoczatek = next; // Jeśli to pierwszy element, przesuwa początek
            if (prev)
                prev->m_pNastepny = next; // Łączy poprzedni element z następnym
            if (next)
                next->m_pPoprzedni = prev; // Łączy następny element z poprzednim
            m_nLiczbaPracownikow--;       // Zmniejsza licznik pracowników
            delete test;                  // Usuwa bieżący element
            break;
        }
        test = test->m_pNastepny; // Przechodzi do kolejnego elementu
    }
}

// Wyświetla wszystkich pracowników
void ListaPracownikow::WypiszPracownikow() const
{
    if (m_pPoczatek == nullptr) // Jeśli lista jest pusta
    {
        std::cout << "Brak pracownikow w liscie." << std::endl;
        return;
    }

    Pracownik *p = m_pPoczatek;
    int i = 0;
    while (p != nullptr) // Przechodzi przez listę
    {
        std::cout << i << "\t"; // Wyświetla indeks
        p->Wypisz();           // Wyświetla dane pracownika
        std::cout << std::endl;
        p = p->m_pNastepny;    // Przechodzi do następnego elementu
        i++;
    }
}

// Szuka pracownika na podstawie nazwiska i imienia
const Pracownik *ListaPracownikow::Szukaj(const char *nazwisko, const char *imie) const
{
    Pracownik *test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez listę
    {
        if (strcmp(test->Nazwisko(), nazwisko) == 0 && strcmp(test->Imie(), imie) == 0)
        {
            return test; // Zwraca znalezionego pracownika
        }
        test = test->m_pNastepny; // Przechodzi do następnego elementu
    }
    return nullptr; // Jeśli pracownika nie ma, zwraca `nullptr`
}
