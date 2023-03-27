CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR=.
OBJ=obj

__start__: ${TRGDIR}/uklad_rownan
		./${TRGDIR}/uklad_rownan rownanie_z.txt

${OBJ}:
		mkdir -p ${OBJ}

${TRGDIR}/uklad_rownan: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o
		g++ -o ${TRGDIR}/uklad_rownan ${OBJ}/main.o ${OBJ}/LZespolona.o

${OBJ}/main.o: src/main.cpp inc/Wektor.hh inc/LZespolona.hh inc/Macierz.hh inc/UkladRownanLiniowych.hh inc/rozmiar.h
		g++ -c ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh inc/Wektor.hh
		g++ -c ${CXXFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp
