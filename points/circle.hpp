#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "point.hpp"
class Circle:private Point{
	private:
		double radius;
	public:
		Circle(double x,double y,double radius);
		~Circle();
		Circle& moveTo(double x,double y);
		Circle& move(double x,double y);
		Point getCentre();
		double getradius();
};
#endif
