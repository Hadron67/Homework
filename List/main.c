#include <stdio.h>
#include "list.h"
void printInt(void* a){
	printf("%d\n",*((int*)a));
}
int main(){
	List* test=list_new();
	int i=2;
	int j=3;
	int k=0;
	list_push(test,node_new(&i));
	list_push(test,node_new(&j));
	list_insert(test,node_new(&k),2);
	list_print(test,printInt);
	list_free(test,NULL);
}
