#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

template <typename Typ, int Wymiar>
class Macierz{

    Wektor<Typ, Wymiar> wiersz[Wymiar];

    public:

    Macierz() = default;
    Macierz(double tab[ROZMIAR][ROZMIAR]);

    const Wektor<Typ, Wymiar> &operator [] (int wie) const {return wiersz[wie];}
    Wektor<Typ, Wymiar> &operator [] (int wie) {return wiersz[wie];}

    Macierz<Typ, Wymiar> operator+ (const Macierz <Typ, Wymiar> mac) const;
    Wektor<Typ, Wymiar> operator* (Wektor<Typ, Wymiar> wek) const;

    void zamien(int ktory, int z_ktorym);
    void transponuj();
};

template<typename Typ,int Wymiar>
Macierz<Typ, Wymiar> Macierz<Typ, Wymiar>::operator+ (const Macierz<Typ, Wymiar> mac) const {

    Macierz<Typ, Wymiar> wynik;

    for (int ind = 0; ind < Wymiar; ++ind){
        wynik[ind] = wiersz[ind] + mac[ind];
    }

    return wynik;
}

template<typename Typ,int Wymiar>
Wektor<Typ, Wymiar> Macierz<Typ, Wymiar>::operator* (Wektor<Typ, Wymiar> wek) const{

    Wektor<Typ, Wymiar> wynik;

    for (int i = 0; i < ROZMIAR; ++i){
        for (int j = 0; j < ROZMIAR; ++j){
            wynik[i] = wynik[i] + (wiersz[i][j] * wek[j]);
    }}

    return wynik;
}

template<typename Typ,int Wymiar>
void Macierz<Typ, Wymiar>::transponuj(){

    Macierz tmp;

    for (int i = 0; i < ROZMIAR; ++i){
        for (int j = 0; j < ROZMIAR; j++)
        {
            tmp[i][j] = wiersz[i][j];
        }
    }

    for (int i = 0; i < ROZMIAR; ++i){
        for (int j = 0; j < ROZMIAR; j++)
        {
            wiersz[i][j] = tmp[j][i];
        }
    }
}

template<typename Typ, int Wymiar>
std::ostream& operator<< (std::ostream& output, const Macierz <Typ, Wymiar> &mac){ 
    
    for (int i = 0; i < ROZMIAR; ++i){
        output << mac[i];
    }
    
    return output;
}

template<typename Typ, int Wymiar>
std::istream& operator>> (std::istream& input, Macierz <Typ, Wymiar> &mac){ 
    
    for (int i = 0; i < ROZMIAR; ++i){
        input >> mac[i];
    }

    return input;
}

#endif