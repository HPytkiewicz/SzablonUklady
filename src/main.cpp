#include <iostream>
#include <iomanip>
#include "SMacierz.hh"
#include "SWektor.hh"
#include "LZespolona.hh"
#include "SUkladRownan.hh"
#include <fstream>

int main(){

  std::ifstream myfile;
  std::string nazwa;
  bool is_real = true;
  std::cout << "Podaj nazwe otwieranego pliku: " << std::endl;
  std::cin >> nazwa;
  myfile.open(nazwa);
  if(!myfile.is_open()){
    std::cerr << ERRORNAME << std::endl;
    exit(0);
  }

  char a = myfile.peek();
  if(a=='(')
    is_real=false;

  if(is_real){
    UkladRownanLiniowych<double,5> UklRownR;
    Wektor<double,5> WynikR;
    Wektor<double,5> Wektor_bleduR;

      myfile >> UklRownR;
      if(myfile.eof()){
	std::cerr << ERROREOF << std::endl;
	exit(0);
      }

  myfile.close();
  if(!std::cin.good()){
    std::cerr<<ERRORLOAD<<std::endl;
    exit(0);
  }
  std::cout << "Wyznacznik: " << UklRownR.pobierzMacierz().wyznacznik() << std::endl;

  std::cout << "Uklad Rownan: " << std::endl << UklRownR << std::endl;
  WynikR = UklRownR.oblicz();
  std::cout << "Wynik: " << WynikR << std::endl;
  Wektor_bleduR = UklRownR.pobierzMacierz()*WynikR - UklRownR.pobierzWektor();
  std::cout << "Wektor bledu: Ax - b = " << Wektor_bleduR << std::endl;
  std::cout << "Dlugosc wektoru bledu: |Ax - b| = " << Wektor_bleduR.dlugosc() << std::endl;


  } else {
    UkladRownanLiniowych<LZespolona,5> UklRownL;
    Wektor<LZespolona,5> WynikL;
    Wektor<LZespolona,5> Wektor_bleduL;

      myfile >> UklRownL;
      if(myfile.eof()){
	std::cerr << ERROREOF << std::endl;
	exit(0);
      }

  myfile.close();
  if(!std::cin.good()){
    std::cerr<<ERRORLOAD<<std::endl;
    exit(0);
  }
  std::cout << "Wyznacznik: " << UklRownL.pobierzMacierz().wyznacznik() << std::endl;

  std::cout << "Uklad Rownan: " << std::endl << UklRownL << std::endl;
  WynikL = UklRownL.oblicz();
  std::cout << "Wynik: " << WynikL << std::endl;
  Wektor_bleduL = UklRownL.pobierzMacierz()*WynikL - UklRownL.pobierzWektor();
  std::cout << "Wektor bledu: Ax - b = " << Wektor_bleduL << std::endl;
  std::cout << "Dlugosc wektoru bledu: |Ax - b| = " << Wektor_bleduL.dlugosc() << std::endl;
  }

}
