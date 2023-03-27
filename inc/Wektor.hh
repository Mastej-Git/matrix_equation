#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include "rozmiar.h"

template <typename Typ, int Wymiar>
class Wektor
{
    Typ wyraz[Wymiar];
public:
    Wektor(){ for (Typ &w_wyraz: wyraz)w_wyraz = 0;  }

    Typ operator[] (int index) const {return wyraz[index];}
    Typ &operator[] (int index) {return wyraz[index];}

    Wektor<Typ, Wymiar> operator+ (Wektor <Typ, Wymiar> &wek) const;
    Wektor<Typ, Wymiar> operator- (Wektor <Typ, Wymiar> &wek) const;
    Wektor<Typ, Wymiar> operator* (double &tmp) const;
    Wektor<Typ, Wymiar> operator/ (Typ &tmp) const;

    Typ iloczyn_skalarny(Wektor<Typ, Wymiar> wek_2);
};

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar> Wektor<Typ, Wymiar>::operator+ (Wektor<Typ, Wymiar> &wek) const{

    Wektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] + wek[i];
    }

    return wynik;    
}

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar> Wektor<Typ, Wymiar>::operator- (Wektor<Typ, Wymiar> &wek) const{

    Wektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] - wek[i];
    }

    return wynik;
}

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar> Wektor<Typ, Wymiar>::operator* (double &tmp) const{

    Wektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] * tmp;
    }

    return wynik;
}

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar> Wektor<Typ, Wymiar>::operator/ (Typ &tmp) const{

    Wektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] / tmp;
    }

    return wynik;
}

template<typename Typ, int Wymiar>
std::ostream& operator<< (std::ostream& output, const Wektor <Typ, Wymiar> &wek){

    for (int i = 0; i < Wymiar; ++i)    {
        output << wek[i] << " ";
    }

    output << std::endl;
    
    return output;
}

template<typename Typ, int Wymiar>
std::istream& operator>> (std::istream& input,  Wektor <Typ, Wymiar> &wek){

    for (int i = 0; i < Wymiar; ++i)    {
        input >> wek[i];
    }
    
    return input;
}
/*
template<typename Typ, int Wymiar>
Typ Wektor<Typ, Wymiar>::iloczyn_skalarny(Wektor<Typ, Wymiar> wek_2){

    double wynik;

    for (int i = 0; i < ROZMIAR; ++i){
        wynik += wyraz[i] * wek_2[i];
    }

    return wynik;  
}
*/
#endif