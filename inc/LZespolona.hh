#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

#include "rozmiar.h"

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona(): re(0), im(0) {};
  LZespolona(double _re, double _im): re(_re), im(_im) {};
  explicit LZespolona (double _re): re(_re), im(0) {};

  LZespolona & operator = (double _re) {re = _re; im=0; return (*this);};
};

LZespolona  operator + (const LZespolona Skl1, const LZespolona  Skl2);

LZespolona operator - (const LZespolona Skl1,const LZespolona Skl2);

LZespolona operator * (const LZespolona Skl1,const LZespolona Skl2);

LZespolona operator / (const LZespolona Skl1, const LZespolona Skl2);

double modul(const LZespolona Skl1);

LZespolona operator += (LZespolona Skl1, const LZespolona Skl2);

LZespolona sprzezenie(const LZespolona Skl1);

LZespolona operator / (const LZespolona Skl1, double R1);

LZespolona operator * (const LZespolona Skl1, double R1);

bool operator ==(const LZespolona SKl1,const LZespolona Skl2);
bool operator !=(const LZespolona SKl1,const LZespolona Skl2);
bool operator ==(const LZespolona SKl1, const double R1);
bool operator !=(const LZespolona SKl1, const double R1);

std::ostream & operator <<(std::ostream & strm,const LZespolona & Skl1);

std::istream & operator >>(std::istream & strm,LZespolona & Skl1);

#endif
