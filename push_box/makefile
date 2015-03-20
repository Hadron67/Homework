XX=gcc
obj=main.o map.o
arg=-std=c99 -g -ggdb
main:$(obj)
	$(XX) -o main $(obj)
	-rm $(obj)
main.o:main.c map.h
	$(XX) -c -o main.o main.c $(arg)
map.o:map.c
	$(XX) -c -o map.o map.c $(arg)
soor:
	-rm $(obj)

