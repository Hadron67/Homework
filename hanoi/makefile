XX=gcc
OBJ=main.o
INC=-I include/
hanoi:$(OBJ)
	$(XX) -o hanoi $(OBJ)
	-rm $(OBJ)
main.o:main.c
	$(XX) -c -o main.o main.c
soor:
	-rm hanoi
