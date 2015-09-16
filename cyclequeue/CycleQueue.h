/* file for the homework : cycle queue (exercise 2)
   header of the CycleQueue
*/
#ifndef CYCLEQUEUE_H
#define CYCLEQUEUE_H
#define CYCLEQUEUE_SIZE 10
#define DATATYPE int
typedef struct queue {
	DATATYPE data[CYCLEQUEUE_SIZE + 1];
	int base;
	int front;
}Queue;
Queue * queue_new ();
int queue_offer (Queue * q,DATATYPE t);
int queue_pull (Queue * q);
DATATYPE queue_front(Queue * q);
void queue_print (Queue * q,FILE * f);
#endif
