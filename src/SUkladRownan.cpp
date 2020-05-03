#include "SUkladRownan.hh"
#include <iomanip>

// Zwraca wektor ukladu rownan
template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::pobierzWektor() const
{
  return wektor;
}

// Wczytuje wektor do ukladu rownan
template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::ustawWektor(const Wektor<TYP,ROZMIAR> & wektor2){
  this->wektor = wektor2;
}

// Zwraca macierz ukladu rownan
template<class TYP, int ROZMIAR>
const Macierz<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::pobierzMacierz() const
{
  return macierz;
}

// Wczytuje macierz do ukladu rownan
template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::ustawMacierz(const Macierz<TYP,ROZMIAR> & macierz2){
  this->macierz = macierz2;
}

// Rozwiazanie ukladu rownan
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::oblicz() const{
  Macierz<TYP,ROZMIAR> macierzpom(this->macierz);
  Wektor<TYP,ROZMIAR> wynik;
  TYP wyznacznikPom;

  wyznacznikPom=macierzpom.wyznacznik();

    for(int i=0;i<ROZMIAR; ++i){
      macierzpom[i]=wektor;
      wynik[i]=macierzpom.wyznacznik();
      macierzpom[i]=macierz[i]; 
    }
    if(wyznacznikPom !=0){
      for(int i=0;i<ROZMIAR; ++i){
	wynik[i]=wynik[i]/wyznacznikPom;
      }
      return wynik;
    } else{
      std::cerr << ERRORNOANSWER << std::endl;
      exit(1);
    }

}

// Wczytanie ukladu rownan
template<class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown){
  Wektor<TYP,ROZMIAR> pomocWektor;
  Macierz<TYP,ROZMIAR> pomocMacierz;
  Strm >> pomocMacierz >> pomocWektor;

  UklRown.ustawMacierz(pomocMacierz);
  UklRown.ustawWektor(pomocWektor);
  return Strm;

}

// Wyswietlenie ukladu rownan
template<class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown){

  Macierz<TYP,ROZMIAR> pomocnicza(UklRown.pobierzMacierz().transponuj());
  
  for (int i = 0; i < ROZMIAR; i++){
    Strm <<  " |" << pomocnicza[i] << "| " << " |x_" << i+1 << "|"<< std::setw(2) << (i==(int)(ROZMIAR/2)?'=':' ') << std::setw(2) << "|";
      Strm << std::setw(SKIP) << UklRown.pobierzWektor()[i] << "|" << std::endl;
  }
}
