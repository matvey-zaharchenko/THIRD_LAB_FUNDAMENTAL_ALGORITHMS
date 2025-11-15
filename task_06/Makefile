all: funcs.o main.o
	gcc -std=c11 funcs.o main.o -o main

funcs.o: funcs.c
	gcc -std=c11 -c funcs.c -o funcs.o

main.o: main.c 
	gcc -std=c11 -c main.c -o main.o