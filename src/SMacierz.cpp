#include "SMacierz.hh"
#include "LZespolona.hh"
#include <iomanip>
#include <iostream>

// Odwolanie sie do indexu macierzy
template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR>  & Macierz<TYP,ROZMIAR>::operator[] (int index) const{

  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Odwolanie sie do indexu macierzy
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int index){

  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Dodawanie macierzy
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator +(const Macierz<TYP,ROZMIAR> & macierz) const{
  Macierz<TYP,ROZMIAR> pomocnicza;
  for(int i =0; i< ROZMIAR; i++)
    pomocnicza[i]=(*this)[i] + macierz[i];
  return pomocnicza;
}

// Odejmowanie macierzy
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator -(const Macierz<TYP,ROZMIAR> & macierz) const
{
  Macierz<TYP,ROZMIAR> pomocnicza;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomocnicza[i] = (*this)[i] - macierz[i];
  }
  return pomocnicza;
}

// Mnozenie macierzy i liczby
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator *(double a) const 
{
  Macierz<TYP,ROZMIAR> pomocnicza;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomocnicza[i] = (*this)[i] * a;
  }
  return pomocnicza;
}

// Porownywanie macierzy (czy sa rowne)
template<class TYP, int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator == (const Macierz<TYP,ROZMIAR> & Macierz2) const
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != Macierz2[i])
      return false;
  }
  return true;
}

// Porownywanie macierzy (czy nie sa rowne)
template<class TYP, int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator != (const Macierz<TYP,ROZMIAR> & Macierz2) const
{
  return !(*this==Macierz2);
}

// Transopnuje macierz
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::transponuj() const
{
  Macierz<TYP,ROZMIAR> wynikowa;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        wynikowa[j][i]= (*this)[i][j];
  
  return wynikowa;
}

/*
// Oblicza dopelnienie macierzy
template<class TYP, int ROZMIAR>
double Macierz<TYP,ROZMIAR>::dopelnienie(int x, int y) const{
  double pomoc;
  if(x< 0 || x >= ROZMIAR || y<0 || y >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  pomoc= (*this)[(x+1)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+2)%ROZMIAR][(y+2)%ROZMIAR] - (*this)[(x+2)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+1)%ROZMIAR][(y+2)%ROZMIAR];
  return pomoc;
}

// Oblicza dopelnienie macierzy liczb zespolonych
template<>
LZespolona Macierz<LZespolona,5>::dopelnienie(int x, int y) const{
  LZespolona pomoc;
  if(x< 0 || x >= ROZMIAR || y<0 || y >= ROZMIAR){
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  pomoc= (*this)[(x+1)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+2)%ROZMIAR][(y+2)%ROZMIAR] - (*this)[(x+2)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+1)%ROZMIAR][(y+2)%ROZMIAR];
  return pomoc;
}

// Oblicza macierz odwrotna
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::odwroc() const{
  Macierz macierzpom;
  double wyznacznik=(*this).wyznacznik(sarrus);
  if(wyznacznik != 0){
    for(int j=0; j<ROZMIAR; j++)
      for(int i=0; i<ROZMIAR; i++)
	macierzpom[i][j]=(*this).dopelnienie(i,j) / wyznacznik;
  }else{
    exit(0);
  }
  return macierzpom.transponuj();
}

*/
// Mnozenie macierzy i wektora
template<class TYP, int ROZMIAR>
 Wektor<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator *(const Wektor<TYP,ROZMIAR> & wektor) const
{
  Wektor<TYP,ROZMIAR> wynik;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    for (int j = 0; j < ROZMIAR; j++)    
    {
      wynik[i] += (*this)[j][i] * wektor[j];
    }
  }
  return wynik;
}

// Mnozenie dwoch macierzy
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator *(const Macierz<TYP,ROZMIAR> &macierz) const
{
  Macierz<TYP,ROZMIAR> wynik;
  Macierz<TYP,ROZMIAR> pomoc=((*this).transponuj());
  for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
      wynik[j][i] += pomoc[j] * macierz[i];
  return wynik;
}

// Mnozenie liczby rzeczywistej i macierzy (odwrotna kolejnosc)
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> operator *(double a, const Macierz<TYP,ROZMIAR> macierz)
{
  return macierz*a;
}

/*
// Obliczenie wyznacznika macierzy
template<class TYP, int ROZMIAR>
double Macierz<TYP,ROZMIAR>::wyznacznik(metodaWyznacznika metoda) const{

  double pomoc=0;
  switch (metoda){
  case sarrus:
    for(int i=0; i<ROZMIAR; i++)
      pomoc += (*this)[i % ROZMIAR][0] * (*this)[(i+1) % ROZMIAR][1] * (*this)[(i+2) % ROZMIAR][2];
    for(int i=0; i<ROZMIAR; i++)
      pomoc -= (*this)[i % ROZMIAR][0] * (*this)[(i+2) % ROZMIAR][1] * (*this)[(i+1) % ROZMIAR][2];
    return pomoc;
    
  case laplace:
    for(int i=0; i<ROZMIAR; i++)
      pomoc+= (*this)[i][0] * ((*this).dopelnienie(i,0));
    return pomoc;
  }
  std::cerr << ERRORNOENUM << std::endl;
  exit(0);
  
}
*/

// Wczytanie macierzy
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, Macierz<TYP,ROZMIAR> &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  { 
    strm>>macierz[i];
  }
  return strm;
}

// Wypisanie macierzy
template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Macierz<TYP,ROZMIAR> &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  {
     for (int j = 0; j < ROZMIAR; j++)
     {
       strm << std::setw(SKIP) << macierz.transponuj()[i][j];
     }
   strm  << std::endl;
  }
  return strm;
}
