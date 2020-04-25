#include <iostream>
#include <iomanip>
#include "SWektor.hh"
#include "LZespolona.hh"

int main(){
Wektor<LZespolona,5> D3;
 LZespolona L1 = {2,3};
  D3[0] = {1,1};
  std::cout << D3 << std::endl;
  std::cout << D3.dlugosc() << std::endl;
  std::cout << L1 << std::endl;
  return 0;

}
