#include <iostream>
#include <iomanip>
#include "SWektor.hh"
#include "LZespolona.hh"

int main(){
  Wektor<LZespolona,5> W1;
  LZespolona L1;
  L1={2,1};
  for(double i=0;i<ROZMIAR;i++)
    W1[i]={i,i};
  std::cout << L1 << std::endl << W1 << std::endl;

  return 0;

}
