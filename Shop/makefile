CC=gcc
OBJ=list.o main.o shop.o
ARG=-std=c99 -g -ggdb
main:$(OBJ)
	$(CC) -o main $(OBJ)
	-rm $(OBJ)
list.o:list.c 
	$(CC) -c -o list.o list.c $(ARG)
shop.o:shop.c list.h
	$(CC) -c -o shop.o shop.c $(ARG)
main.o:main.c shop.h
	$(CC) -c -o main.o main.c $(ARG)

