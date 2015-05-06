CC=gcc
CXX=g++
OBJ=main.o point.o circle.o
main:$(OBJ)
	$(CXX) -o main $(OBJ)
main.o:main.cpp circle.hpp
	$(CXX) -c -o main.o main.cpp
point.o:point.cpp point.hpp
	$(CXX) -c -o point.o point.cpp
circle.o:circle.cpp circle.hpp point.hpp
	$(CXX) -c -o circle.o circle.cpp
.PHONY:soor
soor:
	-rm $(OBJ)
	-rm main
