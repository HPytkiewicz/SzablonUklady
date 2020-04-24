#include <iostream>
#include <Wektor.hh>
#include <LZespolona.hh>

int main(){
  LZespolona L1 = utworz(2,3);
  Wektor W1(2,1,2);

  std::cout << L1 << std::endl << W1 << std::endl;

  return 0;

}
