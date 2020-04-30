#include "SWektor.hh"
#include "LZespolona.hh"
#include <cmath>
#include <iomanip>


// Odwolanie sie do indexu wektora (setter)
template<class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[] (int index) const{
  
  if(index <0 || index >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Odwolanie sie do indexu wektora (getter)
template<class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[] (int index){
  if(index < 0 || index >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Dodanie wektorow
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (Wektor<TYP,ROZMIAR> const &wektor) const{
  Wektor<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] + wektor[i];
  return wynik;
}

// Odejmowanie wektorow
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (Wektor<TYP,ROZMIAR> const &wektor) const{
  Wektor<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i] - wektor[i];
  return wynik;
}

// Mnozenie wektorow
template<class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator * (Wektor<TYP,ROZMIAR> const &wektor) const{
  TYP wynik(0.0);
  for(int i=0;i<ROZMIAR;i++)
    wynik+=(*this)[i] * wektor[i];
  return wynik;
}

// Mnozenie wektora i liczby rzeczywistej
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (TYP a) const{
  Wektor<TYP, ROZMIAR> wynik;
  
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]*a;
  
  return wynik;
}

// Dzielenie wektora i liczby rzeczywistej
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (TYP a) const{
  Wektor<TYP,ROZMIAR> wynik;
  if(a!=0.0){
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=(*this)[i]/a;
  return wynik;
  }else
    exit(1);
}

// Zwraca dlugosc wektora
template<class TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const{
  double wynik=0;
  for(int i=0;i<ROZMIAR; i++){
    wynik+=(*this)[i]*(*this)[i];
  }
  return sqrt(wynik);
}

template<>
double Wektor<LZespolona,5>::dlugosc() const{
  double wynik;
  LZespolona pomoc;
  for(int i=0;i<5;++i){
    pomoc=(*this)[i]*(sprzezenie((*this)[i]));
    wynik+=pomoc.re;
  }
  return sqrt(wynik);
}

// Porownanie wektorow (czy sa rowne)
template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> &Wektor2) const{

  for(int i=0; i<ROZMIAR;i++){
    if(abs((*this)[i]-Wektor2[i])>EPSILON)
      return false;
  }
  return true;
}

template<>
bool Wektor<LZespolona,5>::operator == (const Wektor<LZespolona,5> &Wektor2) const{
  for(int i=0;i<5;i++)
    if((*this)[i]!=Wektor2[i])
      return false;
  return true;	       
}

// Porownanie wektorow (czy nie sa rowne)
template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> &Wektor2) const{
  return !((*this)==Wektor2);
}

template<>
bool Wektor<LZespolona,5>::operator != (const Wektor<LZespolona,5> &Wektor2) const{
  return !((*this)==Wektor2);
}
// Mnozenie liczby rzeczywistej razy wektor (odwrotna kolejnosc)
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator*(TYP a, const Wektor<TYP,ROZMIAR> & Wektor2){

  return Wektor2*a;
}

// Wypisanie wektora
template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Wektor<TYP,ROZMIAR> &wektor){

  for(int i=0;i<ROZMIAR; i++)
    strm << std::setw(SKIP) << wektor[i];
  return strm;
}

// Wczytanie wektora
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, Wektor<TYP,ROZMIAR> &wektor){

  for(int i=0;i<ROZMIAR;i++){
    double pomoc;
    strm>>pomoc;
    wektor[i]=pomoc;
  }
  return strm;
}
