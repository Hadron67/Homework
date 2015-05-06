#include<iostream>
#include "circle.hpp"
using namespace std;
int main(int agv,char* ags[]){
	Circle c(0,0,3);
	c.moveTo(1,1).move(0,1);
	cout<<c.getCentre().getY()<<endl;
	return 0;
}
