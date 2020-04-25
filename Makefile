#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: szablon_uklad
	./szablon_uklad

szablon_uklad: obj/main.o obj/Wektor.o obj/LZespolona.o
	g++ -Wall -pedantic -o szablon_uklad obj/main.o obj/Wektor.o obj/LZespolona.o

obj/main.o: src/main.cpp inc/Wektor.hh inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

clean:
	rm -f obj/*.o szablon_uklad
