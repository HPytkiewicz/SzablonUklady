#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "SWektor.hh"
#include "SMacierz.hh"

template<class TYP, int ROZMIAR>
class UkladRownanLiniowych {
  Macierz<TYP,ROZMIAR> macierz;
  Wektor<TYP,ROZMIAR> wektor;

  
  public:
  UkladRownanLiniowych<TYP,ROZMIAR>(){};
  UkladRownanLiniowych<TYP,ROZMIAR>(const Macierz<TYP,ROZMIAR> & macierz2, const Wektor<TYP,ROZMIAR> & wektor2){
    macierz = macierz2; wektor = wektor2;
  };

  const Wektor<TYP,ROZMIAR> & pobierzWektor() const;
  void ustawWektor(const Wektor<TYP,ROZMIAR> & wektor2);
  const Macierz<TYP,ROZMIAR> & pobierzMacierz() const;
  void ustawMacierz(const Macierz<TYP,ROZMIAR> & macierz2);
  
  Wektor<TYP,ROZMIAR> oblicz() const;
};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);                         

#endif
