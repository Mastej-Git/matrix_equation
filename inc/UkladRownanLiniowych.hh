#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

template<typename Typ, int Wymiar>
class UkladRownanLiniowych{

    Macierz<Typ, Wymiar> A;
    Wektor<Typ, Wymiar> b;

    public:
    
    Macierz<Typ, Wymiar>  get_value_mac();
    Wektor<Typ, Wymiar>  get_value_wek();

    void transponuj_macierz();

    void zrob_jeden(UkladRownanLiniowych<Typ, Wymiar> &url, int k);
    void wypisz_info(UkladRownanLiniowych<Typ, Wymiar> &url, int i, int k);
    void wyzeruj_trojkat_bot(UkladRownanLiniowych<Typ, Wymiar> &url);
    void wyzeruj_trojkat_top(UkladRownanLiniowych<Typ, Wymiar> &url);

    Wektor<Typ, Wymiar> oblicz(UkladRownanLiniowych<Typ, Wymiar> &url);


    template<typename T, int W>
    friend Wektor<T, W> oblicz_wektor_bledu(UkladRownanLiniowych<T, W> url, Wektor<T, W> x);

    template<typename T, int W>
    friend std::istream &operator>> (std::istream &input, UkladRownanLiniowych <T, W>&url);

    template<typename T, int W>    
    friend std::ostream &operator<< (std::ostream &output, UkladRownanLiniowych<T, W> &url);
};

template<typename Typ, int Wymiar>
Macierz<Typ, Wymiar>  UkladRownanLiniowych<Typ, Wymiar>::get_value_mac(){

    return A;
}

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar>  UkladRownanLiniowych<Typ, Wymiar>::get_value_wek(){

    return b;
}

template<typename Typ, int Wymiar>
void UkladRownanLiniowych<Typ, Wymiar>::transponuj_macierz(){

    A.transponuj();
}

template<typename Typ, int Wymiar>
void UkladRownanLiniowych<Typ, Wymiar>::zrob_jeden(UkladRownanLiniowych<Typ, Wymiar> &url, int k){

    Typ tmp_1 = url.A[k][k];
    url.A[k] = url.A[k] / tmp_1;
    url.b[k] = url.b[k] / tmp_1;
}

template<typename Typ, int Wymiar>
void UkladRownanLiniowych<Typ, Wymiar>::wypisz_info(UkladRownanLiniowych<Typ, Wymiar> &url, int i, int k){

    std::cout << "Odjecie od wiersza: " << i+1 << " wiersz: " << k+1 << std::endl;
    std::cout << "Przy kazdej iteracji sprawdzane jest, czy wyraz macierzy znajdujacy sie na przekatnej jest rowny 1, jezeli nie jest takze wykonywana operacja dzielenia wiersza przes wartosc tego wyrazu" << std::endl;
    std::cout << std::endl << url.A << std::endl; 
}

template<typename Typ, int Wymiar>
void UkladRownanLiniowych<Typ, Wymiar>::wyzeruj_trojkat_bot(UkladRownanLiniowych<Typ, Wymiar> &url){

    Typ ratio;

    for(int k = 0; k < ROZMIAR - 1; ++k){
        if (url.A[k][k] != 1){
            zrob_jeden(url, k);}

        for (int i = k + 1; i < ROZMIAR; ++i){
            
            ratio = url.A[i][k]/url.A[k][k];
            for (int j = 0; j < ROZMIAR; ++j){
                url.A[i][j] = url.A[i][j] - ratio * url.A[k][j];
            }
            url.b[i] = url.b[i] - ratio * url.b[k];

            wypisz_info(url, i, k);    
    }}
}

template<typename Typ, int Wymiar>
void UkladRownanLiniowych<Typ, Wymiar>::wyzeruj_trojkat_top(UkladRownanLiniowych<Typ, Wymiar> &url){

    Typ ratio;

    for(int k = ROZMIAR-1; k > -1; --k){
        if (url.A[k][k] != 1){
            zrob_jeden(url, k);}

        for (int i = k - 1; i > -1; --i){
            
            ratio = url.A[i][k]/url.A[k][k];
            for (int j = ROZMIAR-1; j > -1; --j){
                url.A[i][j] = url.A[i][j] - ratio * url.A[k][j];
            }
            url.b[i] = url.b[i] - ratio * url.b[k];

            //wypisz_info(url, i, k);  
    }}
}

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar> UkladRownanLiniowych<Typ, Wymiar>::oblicz(UkladRownanLiniowych<Typ, Wymiar> &url){

    wyzeruj_trojkat_bot(url);

    Typ tmp_2 = url.A[ROZMIAR-1][ROZMIAR-1];
    url.A[ROZMIAR-1] = url.A[ROZMIAR-1] / tmp_2;
    url.b[ROZMIAR-1] = url.b[ROZMIAR-1] / tmp_2;

    wyzeruj_trojkat_top(url);

    
    return url.b;
}

template<typename Typ, int Wymiar>
Wektor<Typ, Wymiar> oblicz_wektor_bledu(UkladRownanLiniowych<Typ, Wymiar> url, Wektor<Typ, Wymiar> x){

    Wektor<Typ, Wymiar> wynik;

    wynik = url.A * x - url.b;

    return wynik;
}

template<typename Typ, int Wymiar>
std::istream &operator>> (std::istream &input, UkladRownanLiniowych <Typ, Wymiar>&url){

    input >> url.A;

    input >> url.b;

    return input;
}

template<typename Typ, int Wymiar>
std::ostream &operator<< (std::ostream &output, UkladRownanLiniowych <Typ, Wymiar>&url){

    output << url.A;

    output << url.b;

    return output;
}

#endif