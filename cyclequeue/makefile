# file for the homework : cycle queue (exercise 2)
# this file is the makefile for the for source files.
OBJ=main.o cyclequeue.o
CFLAGS=-c -g -ggdb
all:main
main:$(OBJ)
	$(CC) -o $@ $(OBJ)
main.o:main.c CycleQueue.h
	$(CC) $(CFLAGS) -o $@ $<
cyclequeue.o:CycleQueue.c CycleQueue.h
	$(CC) $(CFLAGS) -o $@ $<
clean:
	-rm $(OBJ) main
