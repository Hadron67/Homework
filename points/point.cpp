#include "point.hpp"
Point::Point(double x,double y){
	this->x=x;
	this->y=y;
}
Point::~Point(){
	
}
Point& Point::moveTo(double x,double y){
	this->x=x;
	this->y=y;
	return *this;
}
Point& Point::move(double x,double y){
	this->x+=x;
	this->y+=y;
	return *this;
}
double Point::getX(){
	return this->x;
}
double Point::getY(){
	return this->y;
}
