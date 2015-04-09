CC=gcc
CXX=g++
OBJ=list.o stack.o main.o
DEBUG=-g -ggdb
main:$(OBJ)
	$(CXX) $(OBJ) -o main
	-rm $(OBJ)
main.o:main.cpp stack.hpp
	$(CXX) -c -o main.o main.cpp $(DEBUG)
stack.o:stack.cpp list.h
	$(CXX) -c -o stack.o stack.cpp $(DEBUG)
list.o:list.c
	$(CC) -c -o list.o list.c -std=c99 $(DEBUG)
.PHONY:soor
soor:
	-rm $(OBJ)
	-rm main

