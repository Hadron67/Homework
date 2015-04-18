CC=gcc
CXX=g++
OBJ=main.o
ARG=-g -ggdb
main:$(OBJ)
	$(CXX) -o main $(OBJ)
main.o:main.cpp tree.hpp tree.cpp
	$(CXX) -c -o main.o main.cpp $(ARGs)
.PHONY:soor
soor:
	-rm $(OBJ)
	-rm main
