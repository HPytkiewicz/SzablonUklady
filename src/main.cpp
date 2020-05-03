#include <iostream>
#include <iomanip>
#include "SMacierz.hh"
#include "SWektor.hh"
#include "LZespolona.hh"

int main(){
 Wektor<LZespolona,5> W1;
 LZespolona L1 = {2,3};
 Macierz<LZespolona,5> M1;
  W1[0] = {1,1};
  std::cin >> M1;
  std::cout << W1 << std::endl;
  std::cout << W1.dlugosc() << std::endl;
  std::cout << L1 << std::endl;
  std::cout << M1 << std::endl;
  std::cout << M1.wyznacznik() << std::endl;
  std::cout << M1.ZmianaKolumn(2,3) << std::endl;
  return 0;

}
