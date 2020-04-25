#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator - (LZespolona Skl1, LZespolona Skl2);

LZespolona operator * (LZespolona Skl1, LZespolona Skl2);

double modul(LZespolona Skl1);

LZespolona sprzezenie(LZespolona Skl1);

LZespolona operator / (LZespolona Skl1, double R1);

LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

LZespolona utworz(double l1, double l2);

bool operator ==(LZespolona SKl1, LZespolona Skl2);

std::ostream & operator <<(std::ostream & strm,LZespolona Skl1);

std::istream & operator >>(std::istream & strm,LZespolona & Skl1);

#endif
