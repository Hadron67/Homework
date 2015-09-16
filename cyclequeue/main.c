/* file for the homework : cycle queue (exercise 2)
   because i will use the CycleQueue in another 
   project,i wrote the data structure and functions
   in a single file (CycleQueue.c).
   this file is the test program of the CycleQueue.
*/
#include<stdio.h>
#include<stdlib.h>
#include "CycleQueue.h"
int main (int agv,char * ags[]){
	Queue * q=queue_new();
	while (1){
		int a;
		char temp[20];
		printf ("Queue>");
		scanf ("%s",temp);
		sscanf (temp,"%d",&a);
		fflush (stdin);
		if (a >= 0){
			if (!queue_offer (q,a)){
				queue_print (q,stdout);
				printf ("\n");
			}
			else{
				queue_print (q,stdout);
				printf ("\nThe queue is full.\n");
			}
		}
		else if (a == -1){
			if (!queue_pull (q)){
				queue_print (q,stdout);
				printf ("\n");
			}
			else{
				queue_print (q,stdout);
				printf ("\nThe queue is empty.\n");
			}
		}
		else{
			printf ("input error.\n");
			free (q);
			return 0;
		}
	}
	return 0;
}
