// this program is free software
// you can redistribute it and/or
// modify under the terms of the 
// GNU General Public License.
#ifndef MAP_H
#define MAP_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct {
	char* data;//'#':wall '_':space 'M':box '.':destiny 'A':person
	int* boxes;
	int width;
	int height;
	int p_x;
	int p_y;
}Map;
void map_init(Map* m,int width,int height);
Map* map_new(int width,int height);
void map_free(Map* m);
void map_print(Map* map);
Map* map_get(int which);
void map_move(Map* map,int action);
int map_isblocked(Map* map,int x,int y);
int map_iswin(Map* map);
void map_init_from_string(Map* m,int width,int height,const char* s);
Map* map_new_from_string(int width,int height,const char* s);
#endif
