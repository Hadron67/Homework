/* file for the homework : cycle queue (exercise 2)
   this file defined the functions of the CycleQueue.
*/
#include<stdlib.h>
#include<stdio.h>
#include "CycleQueue.h"
#define NEW(a) (a *)malloc(sizeof(a));
#define CHECK_INDEX(a) a %= CYCLEQUEUE_SIZE + 1
Queue * queue_new (){
	Queue * q=NEW(Queue);
	q->base = q->front = 0;
}
int queue_offer (Queue * q,DATATYPE t){
	q->data[q->front++] = t;
	CHECK_INDEX(q->front);
	if (q->front == q->base){
		q->front--;
		if(q->front < 0) q->front += CYCLEQUEUE_SIZE + 1;
		return -1;
	}
	else return 0;
}
int queue_pull (Queue * q){
	if (q->base == q->front) return -1;
	q->base++;
	CHECK_INDEX(q->base);
	return 0;
}
DATATYPE queue_front (Queue * q){
	return q->data[q->base];
}
void queue_print (Queue * q,FILE * f){
	int a = q->base;
	while (a != q->front){
		fprintf (f,"%d ",q->data[a]);
		a++;
		CHECK_INDEX(a);
	}
}
