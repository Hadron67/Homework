CC=gcc
CXX=g++
OBJ=main.o #Array.o
main:$(OBJ)
	$(CXX) -o main $(OBJ)
	-rm $(OBJ)
main.o:main.cpp Array.hpp
	$(CXX) -c -o main.o main.cpp
#Array.o:Array.cpp
#	$(CXX) -c -o Array.o Array.cpp 
