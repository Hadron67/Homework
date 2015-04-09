#include<iostream>
#include "stack.hpp"
using namespace std;
int main(int agv,char* ags[]){
	Stack s;
	s<<1;
	s<<2;
	int a;
	s>>a;
	cout<<a<<endl;
	return 0;
}
