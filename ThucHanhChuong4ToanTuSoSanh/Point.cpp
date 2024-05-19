#include "Point.h"

ostream& operator<<(ostream& os, Point& p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

istream& operator>>(istream& is, Point& p)
{
	is >> p.x >> p.y;
	return is;
}

bool operator<(Point p1, Point p2)
{
	Point p0(0, 0);
	return p1.khoangcach(p0) < p2.khoangcach(p0);
}

//bool Point::operator<(Point p2)
//{
//	Point p0(0, 0); //Goc toa do(0,0)
//	return this->khoangcach(p0)<p2.khoangcach(p0);
//}

float Point::khoangcach(Point p2)
{
	return sqrt((this->x - p2.x) * (this->x - p2.x) +
		(this->y - p2.y) * (this->y - p2.y));
}
