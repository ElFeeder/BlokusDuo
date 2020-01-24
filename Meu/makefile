#makefile

all:	BlokusDuo	Clean

Main.o:	Main.c	BlokusDuo.h
	gcc -Wall -pedantic -ansi -g -c Main.c

Board.o:	Board.c	BlokusDuo.h
	gcc -Wall -pedantic -ansi -g -c Board.c

Play.o:	Play.c	BlokusDuo.h
	gcc -Wall -pedantic -ansi -g -c Play.c

BlokusDuo:	Main.o Board.o
	gcc Main.o Board.o -o BlokusDuo

Clean:
	rm Main.o Board.o