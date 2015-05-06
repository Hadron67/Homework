#ifndef POINT_HPP
#define POINT_HPP 
class Point{
	private:
		double x,y;
	public:
		Point(double x,double y);
		virtual ~Point();
		Point& moveTo(double x,double y);
		Point& move(double x,double y);
		double getX();
		double getY();
};
#endif
