#include "circle.hpp"
Circle::Circle(double x,double y,double radius):Point(x,y){
	this->radius=radius;
}
Circle::~Circle(){
	
}
Circle& Circle::moveTo(double x,double y){
	Point::moveTo(x,y);
	return *this;
}
Circle& Circle::move(double x,double y){
	Point::move(x,y);
	return *this;
}
Point Circle::getCentre(){
	return Point(this->getX(),this->getY());
}
double Circle::getradius(){
	return this->radius;
}
