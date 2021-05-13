#
VIEW := View
CONTROLLER := Controller
MODEL := Model

debug := -ggdb3

all: programa
programa: casino juego jugador dosColores mayor13 piedrapapeltijera montyhall controlador vista main
	g++ ${debug} -o Ejecutable Casino.o Juego.o Jugador.o DosColores.o Mayor13.o PiedraPapelTijera.o MontyHall.o Controller.o View.o Main.o
controlador: ${CONTROLLER}/Controller.cpp ${CONTROLLER}/Controller.h ${MODEL}/Juego.h ${MODEL}/Jugador.h ${MODEL}/DosColores.h
	g++ -c ${debug} ${CONTROLLER}/Controller.cpp
juego: ${MODEL}/Juego.cpp ${MODEL}/Juego.h
	g++ -c ${debug} ${MODEL}/Juego.cpp
jugador: ${MODEL}/Jugador.cpp ${MODEL}/Jugador.h
	g++ -c ${debug} ${MODEL}/Jugador.cpp
dosColores: ${MODEL}/DosColores.cpp ${MODEL}/DosColores.h
	g++ -c ${debug} ${MODEL}/DosColores.cpp
mayor13: ${MODEL}/Mayor13.cpp ${MODEL}/Mayor13.h
	g++ -c ${debug} ${MODEL}/Mayor13.cpp
piedrapapeltijera: ${MODEL}/PiedraPapelTijera.cpp ${MODEL}/PiedraPapelTijera.h
	g++ -c ${debug} ${MODEL}/PiedraPapelTijera.cpp
montyhall: ${MODEL}/MontyHall.cpp ${MODEL}/MontyHall.h
	g++ -c ${debug} ${MODEL}/MontyHall.cpp
casino:${MODEL}/Casino.cpp ${MODEL}/Casino.h
	g++ -c ${debug} ${MODEL}/Casino.cpp
vista: ${VIEW}/View.cpp ${VIEW}/View.h ${CONTROLLER}/Controller.h
	g++ -c ${debug} ${VIEW}/View.cpp
main: Main.cpp ${VIEW}/View.h
	g++ -c ${debug} Main.cpp
clean: #comando para borrar los .o
	@echo "limpio los archivos intermediosd de las carpetas ..."+ ${MODEL} + ${VIEW}
	del *.o, del *.exe