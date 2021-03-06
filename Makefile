#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: szablon_uklad
	./szablon_uklad 

szablon_uklad: obj/main.o obj/SWektor.o obj/LZespolona.o obj/SMacierz.o obj/SUkladRownan.o
	g++ -Wall -pedantic -o szablon_uklad obj/main.o obj/SWektor.o obj/LZespolona.o obj/SMacierz.o obj/SUkladRownan.o

obj/main.o: src/main.cpp src/SWektorC.cpp src/LZespolona.cpp src/SMacierzC.cpp src/SUkladRownanC.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/SUkladRownan.o: src/SUkladRownan.cpp src/SUkladRownanC.cpp inc/SUkladRownan.hh
	g++ ${CPPFLAGS} -o obj/SUkladRownan.o src/SUkladRownanC.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/SMacierz.o: src/SMacierz.cpp src/SMacierzC.cpp inc/SMacierz.hh
	g++ ${CPPFLAGS} -o obj/SMacierz.o src/SMacierzC.cpp

obj/SWektor.o: src/SWektor.cpp src/SWektorC.cpp inc/SWektor.hh 
	g++ ${CPPFLAGS} -o obj/SWektor.o src/SWektorC.cpp

clean:
	rm -f obj/*.o szablon_uklad
