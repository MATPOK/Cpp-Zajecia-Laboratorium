#include "Data.h"
#include <iostream>

using namespace std;


Data::Data(int d, int m, int r): m_nDzien(d), m_nMiesiac(m), m_nRok(r)
{
    Koryguj();
}

Data::Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
    m_nDzien = d;
    m_nMiesiac = m;
    m_nRok = r;
    Koryguj();
}


int Data::InfoDzien() const
{
    int dzien = m_nDzien;
    return dzien;
}

int Data::InfoMiesiac() const
{
    int miesiac = m_nMiesiac;
    return miesiac;
}

int Data::InfoRok() const
{
    int rok = m_nRok;
    return rok;
}


void Data::Wypisz() const
{
    cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}


void Data::Wpisz()
{
    cin >> m_nDzien >> m_nMiesiac >> m_nRok;
    Koryguj();
}


void Data::Koryguj()
{
    if (m_nRok % 4 == 0) { //Czy rok jest przest�pny
        if (m_nMiesiac == 2) { //Luty roku  przest�pnego (29 dni)
            if (m_nDzien <= 0 || m_nDzien > 29) { //Nie jest OK
                if (m_nDzien > 14) {
                    m_nDzien = 29;
                }
                else m_nDzien = 1;
            }
        }
    }
    else {
        if (m_nMiesiac == 2) { //Luty roku  przest�pnego (29 dni)
            if (m_nDzien <= 0 || m_nDzien > 28) { //Nie jest OK
                if (m_nDzien > 14) {
                    m_nDzien = 28;
                }
                else m_nDzien = 1;
            }
        }
    }
    if (m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12) { //31 dni
        if (m_nDzien > 31 || m_nDzien < 1) {
            if (m_nDzien > 14) {
                m_nDzien = 31;
            }
            else m_nDzien = 1;
        }
    }
    if (m_nMiesiac == 2 || m_nMiesiac == 4 || m_nMiesiac == 6 || m_nMiesiac == 9 || m_nMiesiac == 11) { //30 dni
        if (m_nDzien > 30 || m_nDzien < 1) {
            if (m_nDzien > 14) {
                m_nDzien = 30;
            }
            else m_nDzien = 1;
        }
    }
    if (m_nMiesiac > 12) { //Wr�c do grudnia
        m_nMiesiac = 12;
    }
    if (m_nMiesiac < 1) {
        m_nMiesiac = 1; //Wr�c do stycznia
    }
    if (m_nDzien > 31) {
        m_nDzien = 31;
    }
    if (m_nDzien < 1) {
        m_nDzien = 1;
    }
}


int Data::Porownaj(const Data& wzor) const
{
    if (m_nDzien == wzor.m_nDzien && m_nMiesiac == wzor.m_nMiesiac && m_nRok == wzor.m_nRok) {
        return 0;
    }
    if (m_nRok < wzor.m_nRok) {
        return 1;
    }
    if (m_nMiesiac < wzor.m_nMiesiac) {
        return 1;
    }
    if (m_nDzien < wzor.m_nDzien) {
        return 1;
    }
    return -1;
}



