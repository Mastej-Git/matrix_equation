#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void Test_sz_double(){

    cout << endl << "Test szablonu double, o rozmiarze: " << ROZMIAR << endl;

    Wektor<double, ROZMIAR> wek1, wek_wynik;
    double mnoznik = 3;

    for (int i = 0; i < ROZMIAR; ++i){
        wek1[i] = i+1;
    }
    
    cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << wek1 << endl
       << endl;

    wek_wynik = wek1*mnoznik;

    cout << "  Wyswietlenie wyniku: W*3" << endl
       << "        " << wek_wynik << endl
       << endl;
       
    wek_wynik = wek1*mnoznik-wek1;
    cout << "  Wyswietlenie wyniku: W*3-W" << endl
       << "        " << wek_wynik<< endl
       << endl;
}

void Test_sz_LZespolona(){

    cout << endl << "Test szablonu LZespolona, o rozmiarze: " << ROZMIAR << endl;

    Wektor<LZespolona, ROZMIAR> wek1, wek_wynik;
    double mnoznik = 3;

    for (double i = 0; i < ROZMIAR; ++i){
        wek1[i].set_value_rl(i);
        wek1[i].set_value_im(i);
    }
    
    cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << wek1 << endl
       << endl;

    wek_wynik = wek1*mnoznik;

    cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << wek_wynik << endl
       << endl;
       
    wek_wynik = wek1*mnoznik-wek1;
    cout << "  Wyswietlenie wyniku: W*mnoznik - W" << endl
       << "        " << wek_wynik<< endl
       << endl;
}

void rownanie_rzeczywiste(ifstream &plik){

   UkladRownanLiniowych<double,  ROZMIAR> ur1 ,ur_tmp;
   Wektor<double,  ROZMIAR> wynik, blad, tmp1;
   Macierz<double,  ROZMIAR> tmp;
   //double d_wek_bledu;

   plik >> ur1;

   ur_tmp = ur1;

   cout << endl << "Start programu" << endl << endl;
   cout << endl << "Macierz A^T:" << endl << endl;

   tmp = ur1.get_value_mac();
   cout << tmp << endl;

   cout << endl << "Wektor wyrazow wolnych" << endl << endl;

   tmp1 = ur1.get_value_wek();
   cout << tmp1 << endl;

   ur1.transponuj_macierz();

   wynik = ur1.oblicz(ur1);

   cout << endl << "Rozwiazanie x = (x1, x2, x3): " << endl;
   cout << wynik;

   tmp = ur1.get_value_mac();
   cout << endl << tmp << endl;
   cout << endl << ur1.get_value_wek() << endl;

   ur_tmp.transponuj_macierz();
   blad = oblicz_wektor_bledu(ur_tmp, wynik);

   cout << endl << "Wektor bledu: Ax - b = " << blad << endl;

   //d_wek_bledu = blad.iloczyn_skalarny(blad);

   //cout << endl << "Dlugosc wektora bledu: ||Ax - b|| = " << sqrt(d_wek_bledu) << endl;
}

void rownanie_zespolone(ifstream &plik){

   UkladRownanLiniowych<LZespolona,  ROZMIAR> ur1 ,ur_tmp;
   Wektor<LZespolona,  ROZMIAR> wynik, blad, tmp1;
   Macierz<LZespolona,  ROZMIAR> tmp;
   //LZespolona d_wek_bledu;

   plik >> ur1;

   ur_tmp = ur1;

   cout << endl << "Start programu" << endl << endl;
   cout << endl << "Macierz A^T:" << endl << endl;

   tmp = ur1.get_value_mac();
   cout << tmp << endl;

   cout << endl << "Wektor wyrazow wolnych" << endl << endl;

   tmp1 = ur1.get_value_wek();
   cout << tmp1 << endl;

   ur1.transponuj_macierz();

   wynik = ur1.oblicz(ur1);

   cout << endl << "Rozwiazanie x = (x1, x2, x3): " << endl;
   cout << wynik;

   tmp = ur1.get_value_mac();
   cout << endl << tmp << endl;
   cout << endl << ur1.get_value_wek() << endl;

   ur_tmp.transponuj_macierz();
   blad = oblicz_wektor_bledu(ur_tmp, wynik);

   cout << endl << "Wektor bledu: Ax - b = " << blad << endl;

   //d_wek_bledu = blad.iloczyn_skalarny(blad);

   //cout << endl << "Dlugosc wektora bledu: ||Ax - b|| = " << sqrt(d_wek_bledu) << endl;
}

int main(int argc, char **argv){

   //Test_sz_double();
   //Test_sz_LZespolona();

   ifstream UrlPlik(argv[1]);
   char c;

   UrlPlik >> c;
   switch (c)
   {
   case 'r':

      rownanie_rzeczywiste(UrlPlik);
      break;
    
   case 'z':

      rownanie_zespolone(UrlPlik);
      break;
   }
}