#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: szablon_uklad
	./szablon_uklad

szablon_uklad: obj/main.o obj/SWektor.o obj/LZespolona.o
	g++ -Wall -pedantic -o szablon_uklad obj/main.o obj/SWektor.o obj/LZespolona.o

obj/main.o: src/main.cpp src/SWektorC.cpp src/LZespolona.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/SWektor.o: src/SWektor.cpp src/SWektorC.cpp inc/SWektor.hh 
	g++ ${CPPFLAGS} -o obj/SWektor.o src/SWektorC.cpp

clean:
	rm -f obj/*.o szablon_uklad
