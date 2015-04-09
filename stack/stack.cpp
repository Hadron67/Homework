#include "stack.hpp"
//
static void int_free(void* a){
	free((int*)a);
}
//
Stack::Stack(){
	this->data=list_new();
}
Stack::~Stack(){
	list_free(this->data,int_free);
}
void Stack::push(int a){
	int* b=New(int);
	*b=a;
	list_push(this->data,node_new(b));
}
int Stack::pop(){
	Node* output;
	int o;
	if(this->data->count>=1){
		output=list_delete(this->data,this->data->count-1);
	}
	else {
		throw "out of bounds!";
	}
	o=*((int*)output->data);
	node_free(output,int_free);
	return o;
}
int Stack::peak(){
	return *((int*)this->data->end->data);
}
int Stack::operator<<(int a){
	this->push(a);
}
void Stack::operator>>(int & a){
	a=this->pop();
}
int Stack::isEmpty(){
	return this->data->count==0;
}
