
#CC = gcc
#CFLAGS = -Wall -Werror
# TODO : redo this Makefile in a better way

src/main		: src/main.o src/qlearning.o src/dfs.o src/functions.o src/mazeEnv.o
	gcc -I include/ -g -o src/main src/main.o src/qlearning.o src/dfs.o src/functions.o src/mazeEnv.o -Wall

src/dfs         : src/dfs.o src/functions.o src/mazeEnv.o
	gcc -I include/ -g -o src/dfs src/dfs.o src/functions.o src/mazeEnv.o -Wall

src/main.o      : src/main.c
	gcc -I include/ -g -o src/main.o -c src/main.c -Wall

src/qlearning.o	: src/qlearning.c
	gcc -I include/ -g -o src/qlearning.o -c src/qlearning.c -Wall

src/dfs.o       : src/dfs.c
	gcc -I include/ -g -o src/dfs.o -c src/dfs.c -Wall

src/functions.o : src/functions.c include/functions.h
	gcc -I include/ -g -o src/functions.o -c src/functions.c -Wall

src/mazeEnv.o   : src/mazeEnv.c include/mazeEnv.h
	gcc -I include/ -g -o src/mazeEnv.o -c src/mazeEnv.c -Wall

clean:
	rm src/*.o

realclean: clean
	rm src/*.x