#include<iostream>
#include "Array.hpp"
using namespace std;
int main(int agv,char* ags[]){
	Array<float> a(10);
	a=10;
	a[5]=2;
	a.push(2);
	a.push(3);
	a.shift();
	cout<<a.length()<<endl;
}
