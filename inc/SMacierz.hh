#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "SWektor.hh"
#include <iostream>
#include "LZespolona.hh"

enum metodaWyznacznika {sarrus, laplace};

template<class TYP, int ROZMIAR>
class Macierz {
  Wektor<TYP,ROZMIAR> tab[ROZMIAR];
  //  double dopelnienie(int x, int y) const;
 public:
  Macierz<TYP,ROZMIAR>();

  const Wektor<TYP,ROZMIAR>  & operator[] (int index) const;
  Wektor<TYP,ROZMIAR> & operator[] (int index);

  Macierz<TYP,ROZMIAR> operator +(const Macierz<TYP,ROZMIAR> & macierz) const;
  Macierz<TYP,ROZMIAR> operator -(const Macierz<TYP,ROZMIAR> & macierz) const;
  Macierz<TYP,ROZMIAR> operator *(const Macierz<TYP,ROZMIAR> & macierz) const;

  Macierz<TYP,ROZMIAR> operator *(double a) const;
  Wektor<TYP,ROZMIAR> operator *(const Wektor<TYP,ROZMIAR> & wektor) const;

  bool operator == (const Macierz<TYP,ROZMIAR> & Macierz2) const;
  bool operator != (const Macierz<TYP,ROZMIAR> & Macierz2) const;

  Macierz<TYP,ROZMIAR> transponuj() const;
  //  Macierz<TYP,ROZMIAR> odwroc() const;


  //  double wyznacznik(metodaWyznacznika metoda = sarrus) const; 
};

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> operator * (double a, const Macierz<TYP,ROZMIAR> macierz);

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, Macierz<TYP,ROZMIAR> &macierz);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Macierz<TYP,ROZMIAR> &macierz);


#endif