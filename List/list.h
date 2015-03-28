#ifndef LIST_H
#define LIST_H
#include<stdlib.h>
#include<stdio.h>
typedef void (*nodeprint)(void* data);
typedef void (*nodefree)(void* _this);
typedef int (*nodeequal)(void* a,void* b);
typedef struct _Node{
	struct _Node* next;
	struct _Node* previous;
	void* data;
}Node;
typedef struct {
	Node* start;
	Node* end;
	int count;
}List;
Node* node_new(void* data);
void node_free(Node* _this,nodefree freefunc);
List* list_new();
void list_free(List* _this,nodefree freefunc);
void list_push(List* _this,Node* newnode);
int list_insert(List* _this,Node* newnode,int position);
Node* list_delete(List* _this,int position);
void list_print(List* _this,nodeprint printfunc);
#endif