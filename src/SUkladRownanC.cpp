#include <iostream>
#include <iomanip>

#include "SUkladRownan.cpp"
#include "LZespolona.hh"

template class UkladRownanLiniowych<double,5>
template std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<double, 5> &UklRown);
template std::ostream & operator << (std::ostream &Strm, UkladRownanLiniowych<double, 5> &UklRown);

template class UkladRownanLiniowych<LZespolona,5>
template std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona, 5> &UklRown);
template std::ostream & operator << (std::ostream &Strm, UkladRownanLiniowych<LZespolona, 5> &UklRown);
