#makefile

all:	BlokusDuo	Clean

Board.o:	Board.c	BlokusDuo.h	Pieces.h
	gcc -Wall -pedantic -ansi -g -c Board.c

Play.o:	Play.c	BlokusDuo.h Pieces.h
	gcc -Wall -pedantic -ansi -g -c Play.c

Main.o:	Main.c	BlokusDuo.h
	gcc -Wall -pedantic -ansi -g -c Main.c

BlokusDuo:	Main.o	Board.o	Play.o
	gcc Main.o Board.o Play.o -o BlokusDuo

Clean:
	rm Main.o Board.o Play.o