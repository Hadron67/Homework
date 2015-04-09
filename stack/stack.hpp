#ifndef STACK_H
#define STACK_H
#include "list.h"
class Stack{
	private:	
		List* data;
	public:
		Stack();
		~Stack();
		void push(int a);
		int pop();
		int peak();
		int operator<<(int a);
		void operator>>(int & a);
		int isEmpty();
};
#endif
