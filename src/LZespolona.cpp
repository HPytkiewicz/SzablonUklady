#include "LZespolona.hh"
#include <iomanip>
#include <cmath>

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (const LZespolona  Skl1, const LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator - (const LZespolona Skl1,const LZespolona Skl2){
  LZespolona Wynik;
  
  Wynik.re=Skl1.re-Skl2.re;
  Wynik.im=Skl1.im-Skl2.im;

  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator * (const LZespolona Skl1,const LZespolona Skl2){
  LZespolona Wynik;
  
  Wynik.re=Skl1.re*Skl2.re-Skl2.im*Skl1.im;
  Wynik.im=Skl1.re*Skl2.im+Skl2.re*Skl1.im;

  return Wynik;
}

/*!
 * Oblicza wartosc bezwzgledna liczby zespolonej
 * Argumenty:
 *    Skl1 - liczba zespolona na ktora naklada sie modul
 * Zwraca:
 *     LIczbe rzeczywista bedaca wartoscia bezwzgledna z liczby zespolonej.
 */

LZespolona operator += (LZespolona Skl1, const LZespolona Skl2){
  Skl1 = Skl1 + Skl2;

  return Skl1;
}

double modul(const LZespolona Skl1){
  double Wynik;

  Wynik=sqrt(pow(Skl1.re,2)+pow(Skl1.im,2));

  return Wynik;
}

/*!
 * Realizuje operacje sprzezenia
 * Argumenty:
 *    Skl1 - liczba zespolona
 * Zwraca:
 *    LIczbe sprzezona do liczby zespolonej
 */

LZespolona sprzezenie(const LZespolona Skl1){
  LZespolona Wynik;
  Wynik.re=Skl1.re;
  Wynik.im=Skl1.im*(-1);

  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywsita.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    R1 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator / (const LZespolona Skl1, double R1){
  LZespolona Wynik;

  Wynik.re=Skl1.re/R1;
  Wynik.im=Skl1.im/R1;

  return Wynik;
}

LZespolona operator * (const LZespolona Skl1, double R1){
  LZespolona Wynik;

  Wynik.re=Skl1.re*R1;
  Wynik.im=Skl1.im*R1;

  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielnia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    ILoraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;

  Wynik= Skl1*sprzezenie(Skl2)/pow(modul(Skl2),2);

  return Wynik;
}

bool operator == (const LZespolona Skl1,const LZespolona Skl2){
  if(abs(Skl1.re-Skl2.re)<=EPSILON && abs(Skl1.im-Skl2.im)<=EPSILON)
    return true;
  else
    return false;
}

bool operator != (const LZespolona Skl1,const LZespolona Skl2){
  return !(Skl1==Skl2);
}

bool operator == (const LZespolona Skl1,const double R1){
  if(abs(Skl1.re-R1)<=EPSILON && Skl1.im==0.0)
    return true;
  else
    return false;
}

bool operator != (const LZespolona Skl1,const double R1){
  return !(Skl1==R1);

}


/*!
 *Funkcja wypisujaca dana liczbe zespolona
 * Argumenty:
 *    Skl1 - liczba zespolona ktora ta funkcja wypisze
 */

std::ostream & operator <<(std::ostream & strm,const LZespolona & Skl1){

  strm<< '(' << Skl1.re << std::showpos << Skl1.im << "i)" << std::noshowpos;
  return strm;
  
}
std::istream & operator >>(std::istream & strm,LZespolona & Skl1){

 char znak;

  strm >> znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
  strm >> Skl1.re >> Skl1.im >> znak;
  if(znak!='i')
    strm.setstate(std::ios::failbit);
  strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
  return strm;
}

/*Dzialania arytmetyczne liczb zespolonych z rzeczywsistymi*/
/*
LZespolona operator +(LZespolona L1, double R1){
  LZespolona wynik;

  wynik.re = L1.re + R1;
  wynik.im = L1.im;

  return wynik;
}

LZespolona operator -(LZespolona L1, double R1){
  LZespolona wynik;

  wynik.re = L1.re - R1;
  wynik.im = L1.im;

  return wynik;
}*/
