// this program is free software
// you can redistribute it and/or
// modify under the terms of the 
// GNU General Public License.
#include <stdio.h>
#include "map.h"
#ifdef __WIN32
	#define CLEAR system("cls")
#else
	#define CLEAR system("clear")
#endif
int main(int agv,char* ags[]){
	printf(
	"SOKOAN game --byCFY\n"
	"this game is based on command line.\n"
	"'#' is wall so you cannot pass,while ' ' is on the \n"
	"opposite,'M' is box that isn't on the detination,\n"
	"'.' are the destinations\n"
	"of the boxes,'A' is YOU.\n"
	"type awds to move,r to reset,and q to quit.\n"
	"press any key to start.\n");
	getchar();
	while(1){
		Map* m=map_get(0);
		int level=1;
		while(1){
			CLEAR;
			map_print(m);
			printf("level %d \n",level);
			printf("maze_command>");
			if(map_iswin(m)) {
				map_free(m);
				if(level>4) break;
				m=map_get(level++);	
			}
			char key=getchar();
			printf("\n");
			switch(key){
				case 'a':
					map_move(m,3);
					break;
				case 'd':
					map_move(m,1);
					break;
				case 'w':
					map_move(m,0);
					break;
				case 's':
					map_move(m,2);
					break;
				case 'r':
					map_free(m);
					m=map_get(level-1);
					break;
				default:;
			}
			if(key=='q') {
				printf("good bye.\n");
				return 1;
			}
		}
		printf("you win!\n");
		printf("play again?(y/n)");
		fflush(stdin);
		char _continue=getchar();
		printf("\n");
		if(_continue=='n') break;
	}
	printf("good bye.\n");
	return 0;
}
