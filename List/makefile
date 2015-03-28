CC=gcc
OBJ=main.o list.o
ARG=-std=c99 -g -ggdb
main:$(OBJ)
	$(CC) -o main $(OBJ)
	-rm $(OBJ)
main.o:main.c list.h
	$(CC) -c -o main.o main.c
list.o:list.c
	$(CC) -c -o list.o list.c $(ARG)
