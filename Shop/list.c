#include "list.h"
Node* node_new(void* data){
	Node* _this=(Node*)malloc(sizeof(Node));
	_this->next=NULL;
	_this->previous=NULL;
	_this->data=data;
	return _this;
}
void node_free(Node* _this,nodefree freefunc){
	if(freefunc!=NULL){
		freefunc(_this->data);
	}
	free(_this);
}
List* list_new(){
	List* _this=(List*)malloc(sizeof(List));
	_this->count=0;
	_this->start=_this->end=NULL;
	return _this;
}
void list_free(List* _this,nodefree freefunc){
	Node* temp=_this->end;
	while(temp!=NULL&&temp->previous!=NULL){
		temp=temp->previous;
		node_free(temp->next,freefunc);
	}
	node_free(temp,freefunc);
	free(_this);
}
void list_push(List* _this,Node* newnode){
	_this->count++;
	if(_this->start==NULL){
		_this->start=_this->end=newnode;
		newnode->previous=newnode->next=NULL;
	}
	else{
		_this->end->next=newnode;
		newnode->previous=_this->end;
		newnode->next=NULL;
		_this->end=newnode;
	}
}
int list_insert(List* _this,Node* newnode,int position){
	if(position>_this->count||position<0){
		return -1;
	}
	else{
		Node* temp=_this->start;
		if(position==0){
			_this->start->previous=newnode;
			newnode->next=_this->start;
			newnode->previous=NULL;
			_this->start=newnode;
			_this->count++;
			return 0;
		}
		if(position==_this->count){
			list_push(_this,newnode);
			return 0;
		}
		for(int i=0;i<position-1;i++){
			temp=temp->next;
		}
		newnode->next=temp->next;
		newnode->previous=temp;
		temp->next->previous=newnode;
		temp->next=newnode;
		_this->count++;
		return 0;
	}
}
Node* list_delete(List* _this,int position){
	if(position>_this->count||position<0){
		return NULL;
	}
	else {
		Node* output;
		if(position==0){
			output=_this->start;
			_this->start=_this->start->next;
			_this->start->previous=NULL;
			output->next=output->previous=NULL;
		}
		else if(position==_this->count-1){
			output=_this->end;
			_this->end=_this->end->previous;
			_this->end->next=NULL;
			output->next=output->previous=NULL;
		}
		else {
			output=_this->start;
			for(int i=0;i<position;i++){
				output=output->next;
			}
			output->previous->next=output->next;
			output->next->previous=output->previous;
			output->next=output->previous=NULL;
		}
		_this->count--;
		return output;
	}
}
void list_print(List* _this,nodeprint printfunc){
	Node* temp=_this->start;
	while(temp!=NULL){
		printfunc(temp->data);
		temp=temp->next;
	}
}
Node* list_get(List* _this,int position){
	if(position>_this->count||position<0){
		return NULL;
	}
	Node* output=_this->start;
	for(int i=0;i<_this->count-1;i++){
		output=output->next;
	}
	return output;
}
Node* list_find(List* _this,void* target,nodeequal comparefunc){
	Node* temp=_this->start;
	while(temp!=NULL){
		if(comparefunc!=NULL){
			if(comparefunc(target,temp->data)){
				return temp;
			}
		}
		else {
			if(target==temp->data){
				return temp;
			}
		}
		temp=temp->next;
	}
	return NULL;
}
